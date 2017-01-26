#include <Header files\Header.h>
#include "Models.h"
#include <GL\glew.h>
#include <GL\freeglut.h>

//Chanage STEP_SCALE to change your speed
const static float STEP_SCALE = Models::speed * 0.1f;
const static int MARGIN = 10;

Camera::Camera(int WindowWidth, int WindowHeight)
{
    m_windowWidth  = WindowWidth;
    m_windowHeight = WindowHeight;
    m_pos          = Vector3f(0.0f, 0.0f, 0.0f);
    m_target       = Vector3f(0.0f, 0.0f, 1.0f);
    m_target.Normalize();
    m_up           = Vector3f(0.0f, 1.0f, 0.0f);

    Init();
}


Camera::Camera(int WindowWidth, int WindowHeight, const Vector3f& Pos, const Vector3f& Target, const Vector3f& Up)
{
    m_windowWidth  = WindowWidth;
    m_windowHeight = WindowHeight;
    m_pos = Pos;

    m_target = Target;
    m_target.Normalize();

    m_up = Up;
    m_up.Normalize();

    Init();
}


void Camera::Init()
{
    Vector3f HTarget(m_target.x, 0.0, m_target.z);
    HTarget.Normalize();
    
    if (HTarget.z >= 0.0f)
    {
        if (HTarget.x >= 0.0f)
        {
            m_AngleH = 360.0f - ToDegree(asin(HTarget.z));
        }
        else
        {
            m_AngleH = 180.0f + ToDegree(asin(HTarget.z));
        }
    }
    else
    {
        if (HTarget.x >= 0.0f)
        {
            m_AngleH = ToDegree(asin(-HTarget.z));
        }
        else
        {
            m_AngleH = 90.0f + ToDegree(asin(-HTarget.z));
        }
    }
    
    m_AngleV = -ToDegree(asin(m_target.y));

    m_OnUpperEdge = false;
    m_OnLowerEdge = false;
    m_OnLeftEdge  = false;
    m_OnRightEdge = false;
    m_mousePos.x  = m_windowWidth / 2;
    m_mousePos.y  = m_windowHeight / 2;

    glutWarpPointer(m_mousePos.x, m_mousePos.y);
}


Vector3f Camera::OnKeyboard(int Key)
{

    if( Key == 'w')
    {
        m_pos += Vector3f((m_target.x * STEP_SCALE), 0, (m_target.z * STEP_SCALE));
    }

    else if( Key == 's')
    {
        m_pos -= Vector3f((m_target.x * STEP_SCALE), 0, (m_target.z * STEP_SCALE));
    }

    else if( Key == 'a' )
    {
        Vector3f Left = m_target.Cross(m_up);
        Left.Normalize();
        Left *= STEP_SCALE;
        m_pos += Left;
    }
	else
    {
        Vector3f Right = m_up.Cross(m_target);
        Right.Normalize();
        Right *= STEP_SCALE;
        m_pos += Right;
    }
    
	return m_pos;
}


void Camera::OnMouse(int x, int y)
{
	if(m_AngleV< -90.0f)
	{
		m_AngleV = -89.0f;
		y = 0;
	}
	if(m_AngleV> 90.0f)
	{
		m_AngleV = 89.0f;
		y = 0;
	}

	m_AngleH += (float)x / 20.0f;
	m_AngleV += (float)y / 20.0f;

    Update();
}


void Camera::OnRender()
{
    bool ShouldUpdate = false;

	if(m_AngleV > 90.0f)
		ShouldUpdate = true;

	if(m_AngleV < 90.0f)
		ShouldUpdate = false;

    if (ShouldUpdate) {
        Update();
    }
}

void Camera::Update()
{
    const Vector3f Vaxis(0.0f, 1.0f, 0.0f);

    // Rotate the view vector by the horizontal angle around the vertical axis
    Vector3f View(1.0f, 0.0f, 0.0f);
    View.Rotate(m_AngleH, Vaxis);
    View.Normalize();

    // Rotate the view vector by the vertical angle around the horizontal axis
    Vector3f Haxis = Vaxis.Cross(View);
    Haxis.Normalize();
    View.Rotate(m_AngleV, Haxis);
       
    m_target = View;
    m_target.Normalize();

    m_up = m_target.Cross(Haxis);
    m_up.Normalize();
}