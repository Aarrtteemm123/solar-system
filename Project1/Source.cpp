// run only through debugger!
// Release x64
// How connect SFML-2.5.0 to project https://www.youtube.com/watch?v=4fPBAYu8PFs&t=521s

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <thread>
#include <iomanip>

#pragma warning(disable : 4996)

using namespace sf;
using namespace std;

void DrawPlanet(CircleShape &line_neptun, CircleShape &line_uran, CircleShape &line_saturn,
	CircleShape &line_upiter, CircleShape &belt_of_asteroids_end,
	CircleShape &belt_of_asteroids_start, CircleShape &line_mars, CircleShape &line_earth,
	CircleShape &line_venera, CircleShape &line_mercury, CircleShape &mercury,
	CircleShape &venera, CircleShape &earth, CircleShape &mars, CircleShape &upiter,
	CircleShape &saturn, CircleShape &uran, CircleShape &neptun, CircleShape &sun,
	RenderWindow &window, bool fl)
{
	if (fl == 0)
	{
		window.clear();
		window.draw(sun);
		window.draw(neptun);
		window.draw(uran);
		window.draw(saturn);
		window.draw(upiter);
		window.draw(mars);
		window.draw(earth);
		window.draw(venera);
		window.draw(mercury);
		window.display();
	}
	else
	{
		window.clear();
		window.draw(line_neptun);
		window.draw(line_uran);
		window.draw(line_saturn);
		window.draw(line_upiter);
		window.draw(belt_of_asteroids_end);
		window.draw(belt_of_asteroids_start);
		window.draw(line_mars);
		window.draw(line_earth);
		window.draw(line_venera);
		window.draw(line_mercury);
		window.draw(sun);
		window.draw(neptun);
		window.draw(uran);
		window.draw(saturn);
		window.draw(upiter);
		window.draw(mars);
		window.draw(earth);
		window.draw(venera);
		window.draw(mercury);
		window.display();
	}
}

void Controls(RenderWindow &window, View &camera, int p)
{
	Vector2f camera_center;
	Vector2i mouse_pos;
	double long zoom = 1;

	if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); }
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		mouse_pos = Mouse::getPosition(window);
		camera_center = window.mapPixelToCoords(mouse_pos);
		camera.setCenter(camera_center);
	}
	if (Keyboard::isKeyPressed(Keyboard::X))
	{
		zoom = 1;
		zoom += 0.1;
		camera.zoom(zoom);
	}
	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		zoom = 1;
		zoom -= 0.1;
		camera.zoom(zoom);
	}
	if (p == 1)
	{
		if (Keyboard::isKeyPressed(Keyboard::Num0))
		{
			camera_center.x = 5000695508;
			camera_center.y = 5000695508;
			camera.setCenter(camera_center);
		}
	}
	if (p == 2)
	{
		if (Keyboard::isKeyPressed(Keyboard::Num0))
		{
			camera_center.x = 960;
			camera_center.y = 540;
			camera.setCenter(camera_center);
			camera.setSize(1920, 1080);
		}
	}
	if (p == 3)
	{
		if (Keyboard::isKeyPressed(Keyboard::Num0))
		{
			camera_center.x = 67291.71875;
			camera_center.y = 69837.1953125;
			camera.setCenter(camera_center);
			camera.setSize(373564.625, 210129.765625);
		}
	}
	window.setView(camera);
}

void InfoPrint()
{
	system("cls");
	cout << "\n ����� 1 - ������� ������\n ������:\n";
	cout << " - ������� ��������� ���� � ���������� 1 ��� - 1 ����� ���� (60fps) � ���������� ��������;\n";
	cout << " - ������� ��������� ������ ������ �� �����;\n";
	cout << " - �������� ������� ������� ������� (1 ��.��. - 1 ��);\n\n";
	cout << " ����� 2 - ��������� ������\n ������:\n - ���� �������� (������,������� �� �-��� ��������);\n\n";
	cout << " ����� 3 - ��������� ������ ��'���� ������� �������\n ������:\n";
	cout << " - ������� ��������� ������ ������ �� �����;\n";
	cout << " - ��������� ���������;\n\n";
	cout << " ��������� - ������������� ������������\n ������:\n";
	cout << " - ��������� �������;\n";
	cout << " - ������������ ������������ MSAA ��� ����� ��������;\n\n";
	cout << " - ���������� - ������� ����������\n ������:\n";
	cout << " - ��������� ��� ������ ����;\n";
	cout << " - ���������� ��� ������ ��������;\n\n";
	cout << " - ����� - ����� � ��������\n ������:\n";
	cout << " - �������� ���������� ������ �� �������� ��������\n\n";
	_getch();
}

int ControlsInfoPrint()
{
	system("cls");
	cout << "\n   ���²ز �����˲��� ������� :\n\n";
	cout << " LeftMouse --> ������������ ������ ������\n";
	cout << " Escape --> ���������� � ����\n";
	cout << " 0 --> ����� (������� ������)\n";
	cout << " 1 --> ������� ( Q -> ���������� �������������)\n";
	cout << " 2 --> ������ (W -> ���������� �������������)\n";
	cout << " 3 --> ����� (E -> ���������� �������������)\n";
	cout << " 4 --> ���� (R -> ���������� �������������)\n";
	cout << " 5 --> ����� (T -> ���������� �������������)\n";
	cout << " 6 --> ������ (Y -> ���������� �������������)\n";
	cout << " 7 --> ���� (U -> ���������� �������������)\n";
	cout << " 8 --> ������ (I -> ���������� �������������)\n";
	cout << " Z --> ����������� ������\n";
	cout << " X --> ³�������� ������\n";
	cout << " A --> ����� � ����� 2 (S -> �����������)\n";
	cout << " M --> ������������ MSAA (Ҳ���� � ����),�� ������������ 4x\n";

	if (_getch() == 109 || _getch() == 252)
	{
		int msaa;
		cout << "\n  ������� ����� ������������ MSAA (�� ������������ 4x)\n\n";
		cout << " 1. ����;\n";
		cout << " 2. 2x;\n";
		cout << " 3. 4x;\n";
		cout << " 4. 8x;\n";
		cout << " 5. 16x;\n";
		cin >> msaa;

		switch (msaa)
		{
		case 1: return 0;
		case 2: return 2;
		case 3: return 4;
		case 4: return 8;
		case 5: return 16;
		default: cout << " �������!!!\n";
			break;
		}
	}
	else { return 4; }
}

void LoadAndSetTexture(Texture &sun_tex, Texture &mercury_tex, Texture &venera_tex,
	Texture &earth_tex, Texture &mars_tex, Texture &upiter_tex, Texture &saturn_tex,
	Texture &uran_tex, Texture &neptun_tex, CircleShape &sun, CircleShape &mercury,
	CircleShape &venera, CircleShape &earth, CircleShape &mars, CircleShape &upiter,
	CircleShape &saturn, CircleShape &uran, CircleShape &neptun)
{
	sun_tex.loadFromFile("image/sun.png");
	mercury_tex.loadFromFile("image/mercury.png");
	venera_tex.loadFromFile("image/venera.png");
	earth_tex.loadFromFile("image/earth.png");
	mars_tex.loadFromFile("image/mars.png");
	upiter_tex.loadFromFile("image/upiter.png");
	saturn_tex.loadFromFile("image/saturn.png");
	uran_tex.loadFromFile("image/uran.png");
	neptun_tex.loadFromFile("image/neptun.png");

	sun.setTexture(&sun_tex);
	mercury.setTexture(&mercury_tex);
	venera.setTexture(&venera_tex);
	earth.setTexture(&earth_tex);
	mars.setTexture(&mars_tex);
	upiter.setTexture(&upiter_tex);
	saturn.setTexture(&saturn_tex);
	uran.setTexture(&uran_tex);
	neptun.setTexture(&neptun_tex);
}

void MusicLoad(Music &music)
{
	int mus_rand = rand() % 3;
	if (mus_rand == 0) { music.openFromFile("music/music1.ogg"); }
	if (mus_rand == 1) { music.openFromFile("music/music2.ogg"); }
	if (mus_rand == 2) { music.openFromFile("music/music3.ogg"); }
}

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1)
	{
		system("cls");
		int menu, msaa = 4;
		cout << " \n   ���� :\n-------------------------------------------------------------------\n\n";
		cout << " 1. ����� 1;\n 2. ����� 2;\n 3. ����� 3;\n 4. ���������;\n 5. ����������;\n 6. �����;\n";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			//������� ���������
			ContextSettings settings;
			settings.antialiasingLevel = msaa;
			RenderWindow window(VideoMode(10000000000, 10000000000), "Solar system", Style::Fullscreen, settings);
			View camera(Vector2f(5000695508, 5000695508), Vector2f(226488096, 127399536));
			window.setFramerateLimit(60);

			Music music;
			MusicLoad(music);
			music.play();
			music.setLoop(1);

			CircleShape sun(695508, 100);
			CircleShape mercury(2440, 100);
			CircleShape venera(6052, 100);
			CircleShape earth(6371, 100);
			CircleShape mars(3390, 100);
			CircleShape upiter(69911, 100);
			CircleShape saturn(58232, 100);
			CircleShape uran(25362, 100);
			CircleShape neptun(24622, 100);
			CircleShape belt_of_asteroids_start(329120000, 1000);
			CircleShape belt_of_asteroids_end(493680000, 1000);
			CircleShape line_mercury(58910000, 1000);
			CircleShape line_venera(109200000, 1000);
			CircleShape line_earth(150600000, 1000);
			CircleShape line_mars(228900000, 1000);
			CircleShape line_upiter(779500000, 1000);
			CircleShape line_saturn(1434000000, 1000);
			CircleShape line_uran(2872000000, 1000);
			CircleShape line_neptun(4496000000, 1000);

			sun.setPosition(5000000000, 5000000000);
			belt_of_asteroids_start.setPosition(4671575508, 4671575508);
			belt_of_asteroids_end.setPosition(4507015508, 4507015508);
			line_mercury.setPosition(4942785508, 4942785508);
			line_venera.setPosition(4892495508, 4892495508);
			line_earth.setPosition(4851095508, 4851095508);
			line_mars.setPosition(4772795508, 4772795508);
			line_upiter.setPosition(4222195508, 4222195508);
			line_saturn.setPosition(3567695508, 3567695508);
			line_uran.setPosition(2129695508, 2129695508);
			line_neptun.setPosition(505695508, 505695508);

			belt_of_asteroids_start.setFillColor(Color::Black);
			belt_of_asteroids_end.setFillColor(Color::Black);
			belt_of_asteroids_start.setOutlineColor(Color::White);
			belt_of_asteroids_end.setOutlineColor(Color::White);
			line_mercury.setFillColor(Color::Black);
			line_mercury.setOutlineColor(Color::Green);
			line_venera.setFillColor(Color::Black);
			line_venera.setOutlineColor(Color::Green);
			line_earth.setFillColor(Color::Black);
			line_earth.setOutlineColor(Color::Green);
			line_mars.setFillColor(Color::Black);
			line_mars.setOutlineColor(Color::Green);
			line_upiter.setFillColor(Color::Black);
			line_upiter.setOutlineColor(Color::Green);
			line_saturn.setFillColor(Color::Black);
			line_saturn.setOutlineColor(Color::Green);
			line_uran.setFillColor(Color::Black);
			line_uran.setOutlineColor(Color::Green);
			line_neptun.setFillColor(Color::Black);
			line_neptun.setOutlineColor(Color::Green);
			belt_of_asteroids_start.setOutlineThickness(1000000);
			belt_of_asteroids_end.setOutlineThickness(1000000);
			line_mercury.setOutlineThickness(1000000);
			line_venera.setOutlineThickness(1000000);
			line_earth.setOutlineThickness(1000000);
			line_mars.setOutlineThickness(1000000);
			line_upiter.setOutlineThickness(1000000);
			line_saturn.setOutlineThickness(1000000);
			line_uran.setOutlineThickness(1000000);
			line_neptun.setOutlineThickness(1000000);

			Texture sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex, upiter_tex,
				saturn_tex, uran_tex, neptun_tex;

			LoadAndSetTexture(sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex,
				upiter_tex, saturn_tex, uran_tex, neptun_tex, sun, mercury, venera,
				earth, mars, upiter, saturn, uran, neptun);

			double long mer_ang = 0, ven_ang = 0, ear_ang = 0, mars_ang = 0,
				upit_ang = 0, sat_ang = 0, uran_ang = 0, nep_ang = 0;
			const double rad = 3.14159265359 / 180;

			while (window.isOpen())
			{
				mercury.setPosition(57910000 * cos(mer_ang) + 5000695508, 57910000 * sin(mer_ang) + 5000695508);
				venera.setPosition(108200000 * cos(ven_ang) + 5000695508, 108200000 * sin(ven_ang) + 5000695508);
				earth.setPosition(149600000 * cos(ear_ang) + 5000695508, 149600000 * sin(ear_ang) + 5000695508);
				mars.setPosition(227900000 * cos(mars_ang) + 5000695508, 227900000 * sin(mars_ang) + 5000695508);
				upiter.setPosition(778500000 * cos(upit_ang) + 5000695508, 778500000 * sin(upit_ang) + 5000695508);
				saturn.setPosition(1433000000 * cos(sat_ang) + 5000695508, 1433000000 * sin(sat_ang) + 5000695508);
				uran.setPosition(2871000000 * cos(uran_ang) + 5000695508, 2871000000 * sin(uran_ang) + 5000695508);
				neptun.setPosition(4495000000 * cos(nep_ang) + 5000695508, 4495000000 * sin(nep_ang) + 5000695508);
				mer_ang -= 0.067438*rad;
				ven_ang -= 0.026702*rad;
				ear_ang -= 0.016427*rad;
				mars_ang -= 0.008738*rad;
				upit_ang -= 0.001385*rad;
				sat_ang -= 0.000557597*rad;
				uran_ang -= 0.00019551*rad;
				nep_ang -= 0.0000996894*rad;

				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					camera.setCenter(mercury.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Q)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
					camera.setCenter(venera.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::W)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3))
				{
					camera.setCenter(earth.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::E)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num4))
				{
					camera.setCenter(mars.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::R)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num5))
				{
					camera.setCenter(upiter.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::T)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num6))
				{
					camera.setCenter(saturn.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Y)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num7))
				{
					camera.setCenter(uran.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::U)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num8))
				{
					camera.setCenter(neptun.getPosition());
					bool fl = false;

					while (fl != true)
					{
						if (Keyboard::isKeyPressed(Keyboard::I)) { fl = true; }
						Controls(window, camera, 1);
						DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
							belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
							line_earth, line_venera, line_mercury, mercury, venera,
							earth, mars, upiter, saturn, uran, neptun, sun, window, 0);
					}
				}
				Controls(window, camera, 1);
				DrawPlanet(line_neptun, line_uran, line_saturn, line_upiter,
					belt_of_asteroids_end, belt_of_asteroids_start, line_mars,
					line_earth, line_venera, line_mercury, mercury, venera, earth,
					mars, upiter, saturn, uran, neptun, sun, window, 1);
			}
			break;
		}
		case 2:
		{
			//��������� ���������
			int n = 200;
			ContextSettings settings;
			settings.antialiasingLevel = msaa;
			RenderWindow window(VideoMode(1920, 1080), "Solar system", Style::Fullscreen, settings);
			View camera(Vector2f(960, 540), Vector2f(1920, 1080));
			window.setFramerateLimit(60);

			Music music;
			MusicLoad(music);
			music.play();
			music.setLoop(1);

			CircleShape sun(30, 100);
			CircleShape mercury(7, 100);
			CircleShape venera(8, 100);
			CircleShape earth(10, 100);
			CircleShape mars(9, 100);
			CircleShape upiter(15, 100);
			CircleShape saturn(14, 100);
			CircleShape uran(13, 100);
			CircleShape neptun(12, 100);

			CircleShape *asteroids = new CircleShape[n];
			Vector2f *aster_trajec = new Vector2f[n];
			float *aster_ang = new float[n];
			float *aster_speed = new float[n];

			Texture aster_tex, aster2_tex, aster3_tex, aster4_tex, aster5_tex;
			aster_tex.loadFromFile("image/ast.png");
			aster2_tex.loadFromFile("image/ast2.png");
			aster3_tex.loadFromFile("image/ast3.png");
			aster4_tex.loadFromFile("image/ast4.png");
			aster5_tex.loadFromFile("image/ast5.png");

			int random_tex;
			for (size_t i = 0; i < n; i++)
			{
				asteroids[i].setRadius(rand() % 10 * 0.1 + 0.5);//�� 0,5 �� 1.5
				random_tex = rand() % 5;
				if (random_tex == 0) { asteroids[i].setTexture(&aster_tex); }
				if (random_tex == 1) { asteroids[i].setTexture(&aster2_tex); }
				if (random_tex == 2) { asteroids[i].setTexture(&aster3_tex); }
				if (random_tex == 3) { asteroids[i].setTexture(&aster4_tex); }
				if (random_tex == 4) { asteroids[i].setTexture(&aster5_tex); }
				aster_trajec[i].x = rand() % 95 + 180;
				aster_trajec[i].y = rand() % 60 + 165;
				aster_speed[i] = (rand() % 11500 + 500) * 0.0001;
				aster_ang[i] = 0;
			}

			sun.setPosition(930, 510);

			Texture sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex, upiter_tex,
				saturn_tex, uran_tex, neptun_tex, sky_tex, sky2_tex, sky3_tex;

			LoadAndSetTexture(sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex,
				upiter_tex, saturn_tex, uran_tex, neptun_tex, sun, mercury, venera,
				earth, mars, upiter, saturn, uran, neptun);

			sky_tex.loadFromFile("image/sky1.png");
			sky2_tex.loadFromFile("image/sky2.png");
			sky3_tex.loadFromFile("image/sky3.png");

			random_tex = rand() % 3;
			Sprite sky;
			if (random_tex == 0) { sky.setTexture(sky_tex); }
			if (random_tex == 1) { sky.setTexture(sky2_tex); }
			if (random_tex == 2) { sky.setTexture(sky3_tex); sky.setScale(1.15, 1.05); }

			double long mer_ang = 0, ven_ang = 0, ear_ang = 0, mars_ang = 0,
				upit_ang = 0, sat_ang = 0, uran_ang = 0, nep_ang = 0;
			const double rad = 3.14159265359 / 180;
			bool fl = false;
			Vector2f cam_size;

			while (window.isOpen())
			{
				for (size_t i = 0; i < n; i++)
				{
					asteroids[i].setPosition(aster_trajec[i].x * cos(aster_ang[i]) + 960, aster_trajec[i].y * sin(aster_ang[i]) + 540);
					aster_ang[i] -= aster_speed[i] * rad;
				}
				mercury.setPosition(60 * cos(mer_ang) + 953, 60 * sin(mer_ang) + 533);
				venera.setPosition(90 * cos(ven_ang) + 952, 85 * sin(ven_ang) + 532);
				earth.setPosition(125 * cos(ear_ang) + 950, 115 * sin(ear_ang) + 530);
				mars.setPosition(170 * cos(mars_ang) + 951, 155 * sin(mars_ang) + 531);
				upiter.setPosition(290 * cos(upit_ang) + 945, 240 * sin(upit_ang) + 525);
				saturn.setPosition(450 * cos(sat_ang) + 946, 300 * sin(sat_ang) + 526);
				uran.setPosition(700 * cos(uran_ang) + 947, 360 * sin(uran_ang) + 527);
				neptun.setPosition(940 * cos(nep_ang) + 948, 500 * sin(nep_ang) + 528);
				mer_ang -= 0.8348*rad;
				ven_ang -= 0.7777*rad;
				ear_ang -= 0.6297*rad;
				mars_ang -= 0.5434*rad;
				upit_ang -= 0.4199*rad;
				sat_ang -= 0.3032*rad;
				uran_ang -= 0.2082*rad;
				nep_ang -= 0.1011*rad;

				cam_size = camera.getSize();
				if (cam_size.x > 1920) { camera.setSize(1920, 1080); }
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					while (fl == false)
					{
						cam_size = camera.getSize();
						if (cam_size.x > 1920) { camera.setSize(1920, 1080); }
						if (Keyboard::isKeyPressed(Keyboard::S)) { fl = true; }
						Controls(window, camera, 2);
						window.clear();
						window.draw(sky);
						for (size_t i = 0; i < n; i++) { window.draw(asteroids[i]); }
						window.draw(sun);
						window.draw(neptun);
						window.draw(uran);
						window.draw(saturn);
						window.draw(upiter);
						window.draw(mars);
						window.draw(earth);
						window.draw(venera);
						window.draw(mercury);
						window.display();
					}
					fl = false;
				}
				Controls(window, camera, 2);
				window.clear();
				window.draw(sky);
				for (size_t i = 0; i < n; i++) { window.draw(asteroids[i]); }
				window.draw(sun);
				window.draw(neptun);
				window.draw(uran);
				window.draw(saturn);
				window.draw(upiter);
				window.draw(mars);
				window.draw(earth);
				window.draw(venera);
				window.draw(mercury);
				window.display();
			}
			break;
		}
		case 3:
		{
			//��������� ������
			float k = 0.1;
			RenderWindow window(VideoMode(1000000 * k, 1000000 * k), "Solar system", Style::Fullscreen);
			View camera(Vector2f(2463.46 * k, 1388720 * k), Vector2f(15225.6 * k, 8564.39 * k));
			window.setFramerateLimit(60);

			Music music;
			MusicLoad(music);
			music.play();
			music.setLoop(1);

			CircleShape sun(695508 * k, 1000);
			CircleShape mercury(2440 * k, 1000);
			CircleShape venera(6052 * k, 1000);
			CircleShape earth(6371 * k, 1000);
			CircleShape mars(3390 * k, 1000);
			CircleShape upiter(69911 * k, 1000);
			CircleShape saturn(58232 * k, 1000);
			CircleShape uran(25362 * k, 1000);
			CircleShape neptun(24622 * k, 1000);

			Font game;
			game.loadFromFile("font/game.ttf");

			Text mer_txt("Mercury", game, 80);
			Text mars_txt("Mars", game, 100);
			Text ven_txt("Venera", game, 100);
			Text ear_txt("Earth", game, 100);
			Text nep_txt("Neptun", game, 500);
			Text uran_txt("Uran", game, 500);
			Text sat_txt("Saturn", game, 800);
			Text upit_txt("Upiter", game, 800);
			Text sun_txt("Sun", game, 5000);

			mer_txt.setPosition(-3000 * k, 1386136 * k);
			mars_txt.setPosition(12880 * k, 1384236 * k);
			ven_txt.setPosition(34984 * k, 1378912 * k);
			ear_txt.setPosition(59088 * k, 1378274 * k);
			nep_txt.setPosition(75830 * k, 1341772 * k);
			uran_txt.setPosition(135074 * k, 1340292 * k);
			sat_txt.setPosition(200798 * k, 1274552 * k);
			upit_txt.setPosition(328262 * k, 1251194 * k);
			sun_txt.setPosition(478084 * k, 0 * k);

			mercury.setPosition(0 * k, 1386136 * k);
			mars.setPosition(14880 * k, 1384236 * k);
			venera.setPosition(36984 * k, 1378912 * k);
			earth.setPosition(59088 * k, 1378274 * k);
			neptun.setPosition(81830 * k, 1341772 * k);
			uran.setPosition(141074 * k, 1340292 * k);
			saturn.setPosition(201798 * k, 1274552 * k);
			upiter.setPosition(328262 * k, 1251194 * k);
			sun.setPosition(478084 * k, 0 * k);

			Texture sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex, upiter_tex,
				saturn_tex, uran_tex, neptun_tex;
			LoadAndSetTexture(sun_tex, mercury_tex, venera_tex, earth_tex, mars_tex,
				upiter_tex, saturn_tex, uran_tex, neptun_tex, sun, mercury, venera,
				earth, mars, upiter, saturn, uran, neptun);

			while (window.isOpen())
			{
				Controls(window, camera, 3);
				window.clear();
				window.draw(mer_txt);
				window.draw(mars_txt);
				window.draw(ven_txt);
				window.draw(ear_txt);
				window.draw(nep_txt);
				window.draw(uran_txt);
				window.draw(sat_txt);
				window.draw(upit_txt);
				window.draw(sun_txt);
				window.draw(sun);
				window.draw(neptun);
				window.draw(uran);
				window.draw(saturn);
				window.draw(upiter);
				window.draw(mars);
				window.draw(earth);
				window.draw(venera);
				window.draw(mercury);
				window.display();
			}
			break;
		}
		case 4:
		{
			msaa = ControlsInfoPrint();
			break;
		}
		case 5:
		{
			InfoPrint();
			break;
		}
		case 6: { return 0; }
		default:cout << "\n�������\n";
			break;
		}
	}
}