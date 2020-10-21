/*
 * ExampleWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#include <cmath>

static constexpr double Pi = acos(-1.);

#include "ExampleWindow.h"

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };//задаетс€ красный цвет массивом значени€ми RGB
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };//задаетс€ зеленый цвет массивом значени€ми RGB
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };//задаетс€ синий цвет массивом значени€ми RGB
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };//задаетс€ голубой цвет массивом значени€ми RGB
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };//задаетс€ пурпурный цвет массивом значени€ми RGB
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };//задаетс€ желтый цвет массивом значени€ми RGB

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);//позвол€ет выполнить тест глубины до выполнени€ фрагментного шейдера.
	glEnable(GL_LIGHTING);//включает освещение
	glEnable(GL_LIGHT0);//включает освещение
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);// задаетс€ цвет фона
	//задаетс€ матрица видимой области
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void ExampleWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//текуща€ матрица будет сделана единичной
	glLoadIdentity();
	//задаютс€ координаты положени€ глаз
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);// производит вращение вокруг вектора

	glBegin(GL_QUADS);
//–исует красную поверхность по заданным точкам координат
	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	glVertex3d(  1., -1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d(  1., -1., -1.);
	//–исует голубую поверхность по заданным точкам координат
	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);
	//–исует зеленую поверхность по заданным точкам координат
	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	//–исует пурпурную поверхность по заданным точкам координат
	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);
	//–исует синию поверхность по заданным точкам координат
	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	//–исует желтую поверхность по заданным точкам координат
	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);


		glEnd();
}

void ExampleWindow::handle_logic()//  од дл€ вращени€. передает координаты в glRotated(_angle, 0., 0., 1.);
{
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

	_eye_level = sin(_angle / 180. * Pi);
}
