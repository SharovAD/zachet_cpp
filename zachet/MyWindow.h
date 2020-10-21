#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

// Объявление класса ExampleWindow как потомка Window
class MyWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle; // Угол поворота модели
	double _eye_level; // Высота уровня глаз
	double _dlin;//Для изменения длинны
	double _vis;//Для изменения высоты
	double _shir;//Для изменения ширины

public:

	// Конструктор класса MyWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// Деструктор класса MyWindow
	virtual ~MyWindow() = default;

	// Метод начальной настройки окна
	virtual void setup() override;

	// Метод отрисовки окна
	virtual void render() override;

	// Метод обработки логики
	virtual void handle_logic() override;

	// Метод обработки клавиш
	virtual void handle_keys(const Uint8 * keys);
};




#endif /* EXAMPLEWINDOW_H_ */
