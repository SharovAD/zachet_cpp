#include <cmath>

static constexpr double Pi = acos(-1.);

#include "MyWindow.h"

MyWindow::MyWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
	_dlin= 0.;//Для изменения длинны
	_vis = 0.;//Для изменения высоты
	_shir = 0.;//Для изменения ширины
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };
//static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };
//static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };
//static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };
//static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };

void MyWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);

	glBegin(GL_QUADS);

	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d(  1.+_dlin, -1.,  1.);
	glVertex3d(  1.+_dlin,  1.+_shir,  1.);
	glVertex3d(  1.+_dlin,  1.+_shir, -1.+_vis);
	glVertex3d(  1.+_dlin, -1., -1.+_vis);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d( -1.,  1.+_shir,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.+_vis);
	glVertex3d( -1.,  1.+_shir, -1.+_vis);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d( -1.,  1.+_shir,  1.);
	glVertex3d(  1.+_dlin,  1.+_shir,  1.);
	glVertex3d(  1.+_dlin,  1.+_shir, -1.+_vis);
	glVertex3d( -1.,  1.+_shir, -1.+_vis);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d(  1.+_dlin, -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.+_vis);
	glVertex3d(  1.+_dlin, -1., -1.+_vis);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d( -1.,  1.+_shir,  1.);
	glVertex3d(  1.+_dlin,  1.+_shir,  1.);
	glVertex3d(  1.+_dlin, -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d(  1.+_dlin,  1.+_shir, -1.+_vis);
	glVertex3d( -1.,  1.+_shir, -1.+_vis);
	glVertex3d( -1., -1., -1.+_vis);
	glVertex3d(  1.+_dlin, -1., -1.+_vis);


//крыша 1-ый скат
	glNormal3d(  0.,  0.,  1.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
		glVertex3d( -1.,  0.,  2.);
		glVertex3d(  1.+_dlin,  0.,  2.);
		glVertex3d(  1.+_dlin, 1.+_shir,  1.);
		glVertex3d( -1., 1.+_shir,  1.);
		//крыша 2-ой скат
		glNormal3d(  0.,  0.,  1.);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
				glVertex3d( -1.,  0.,  2.);
				glVertex3d(  1.+_dlin,  0.,  2.);
				glVertex3d(  1.+_dlin, -1.,  1.);
				glVertex3d( -1., -1.,  1.);

		glEnd();
}

void MyWindow::handle_logic()
{
//	_angle += 1.;
//	if (_angle >= 360.)
//		_angle -= 360.;

//	_eye_level = sin(_angle / 180. * Pi);


}

void MyWindow::handle_keys(const Uint8 * keys)
{
	if (keys[SDL_SCANCODE_RIGHT])
	  {
		_angle -= 1.;
			if (_angle >= 360.)
				_angle -= 360.;

			_eye_level = sin(_angle / 180. * Pi);
	  }
	if (keys[SDL_SCANCODE_LEFT])
		  {
			_angle += 1.;
				if (_angle >= 360.)
					_angle -= 360.;

				_eye_level = sin(_angle / 180. * Pi);
		  }
	if (keys[SDL_SCANCODE_A])
			  {
	          _dlin += 0.01;
			  }
	if (keys[SDL_SCANCODE_Q])
				  {
		          _dlin -= 0.01;
				  }
	if (keys[SDL_SCANCODE_S])
				  {
		_vis += 0.01;
				  }
		if (keys[SDL_SCANCODE_W])
					  {
		_vis -= 0.01;
					  }
		if (keys[SDL_SCANCODE_D])
						  {
			_shir += 0.01;
						  }
				if (keys[SDL_SCANCODE_E])
							  {
			_shir -= 0.01;
							  }
}
