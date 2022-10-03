# include<Siv3D.hpp> // OpenSiv3D v0.6.5

#define bomb 20

Grid<double> mp{
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
};

Grid<double> mp_s{
	{1,1,0,0,0,0,0},
	{1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
};

int flag2 = 0;

double r1 = 0.8, g1 = 0.9, b1 = 1.0;
double r2 = 0.6, g2 = 0.27, b2 = 0.0;
double r3 = 1.0, g3 = 0.7, b3 = 0.02;





void reset(int l, int m) {

	int s = l, t = m;

	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			mp[x][y] = 0;
		}
	}

	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			mp_s[x][y] = 0;
		}
	}

	mp_s[0][0] = 1;
	mp_s[0][1] = 1;
	mp_s[1][0] = 1;
	mp_s[1][1] = 1;


	for (int i = 0; i < bomb; i++) {
		mp[i / 6][i % 6] = -1;
	}

	for (int i = 0; i < Random(10000) + 100; i++) {

		int rx = Random(6);
		int ry = Random(6);

		int x = Random(6);
		int y = Random(6);

		int tmp = mp[rx][ry];
		mp[rx][ry] = mp[x][y];
		mp[x][y] = tmp;

	}

	if (mp[0][0] == -1) {
		for (int i = 35; i > 0; i--) {
			if (mp[i / 6][i % 6] != -1) {
				mp[0][0] = 0;
				mp[i / 6][i % 6] = -1;
				break;
			}
		}
	}

	if (mp[0][1] == -1) {
		for (int i = 35; i > 0; i--) {
			if (mp[i / 6][i % 6] != -1) {
				mp[0][1] = 0;
				mp[i / 6][i % 6] = -1;
				break;
			}
		}
	}

	if (mp[1][0] == -1) {
		for (int i = 35; i > 0; i--) {
			if (mp[i / 6][i % 6] != -1) {
				mp[1][0] = 0;
				mp[i / 6][i % 6] = -1;
				break;
			}
		}
	}

	if (mp[1][1] == -1) {
		for (int i = 35; i > 0; i--) {
			if (mp[i / 6][i % 6] != -1) {
				mp[1][1] = 0;
				mp[i / 6][i % 6] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < 36; i++) {
		int x, y;
		x = i / 6;
		y = i % 6;
		if (mp[x][y] != -1) {

			if (x - 1 >= 0) {
				if (y - 1 >= 0 && mp[x - 1][y - 1] == -1) mp[x][y]++;
				if (mp[x - 1][y] == -1) mp[x][y]++;
				if (y + 1 < 5 && mp[x - 1][y + 1] == -1) mp[x][y]++;
			}

			if (x + 1 <= 5) {
				if (y - 1 >= 0 && mp[x + 1][y - 1] == -1) mp[x][y]++;
				if (mp[x + 1][y] == -1) mp[x][y]++;
				if (y + 1 < 5 && mp[x + 1][y + 1] == -1) mp[x][y]++;
			}

			if (y - 1 >= 0 && mp[x][y - 1] == -1) mp[x][y]++;
			if (y + 1 <= 5 && mp[x][y + 1] == -1) mp[x][y]++;
		}
	}




}

void c_lclick(int x, int y) {

	int l = x, m = y;

	bool grab = 0;

	double mx = Cursor::Pos().x;
	double my = Cursor::Pos().y;

	if (MouseL.pressed())  grab = 1;
	else grab = 0;

	//Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (mx >= 40 + (i) * (440 / l) && mx <= 40 + (i) * (440 / l) + (440 - l * 10) / l && grab == 1 && my >= 40 + (j) * (440 / m) && my <= 40 + (j) * (440 / m) + (440 - m * 10) / m) mp_s[i][j] = 1;
		}
	}


}

void c_rclick(int x, int y) {

	int l = x, m = y;

	bool grab = 0;

	double mx = Cursor::Pos().x;
	double my = Cursor::Pos().y;

	if (MouseR.pressed())  grab = 1;
	else grab = 0;

	//Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (mx >= 40 + (i) * (440 / l) && mx <= 40 + (i) * (440 / l) + (440 - l * 10) / l && grab == 1 && my >= 40 + (j) * (440 / m) && my <= 40 + (j) * (440 / m) + (440 - m * 10) / m && mp_s[i][j] != 2) {
				mp_s[i][j] = 2;
				break;
			}
			else if (mx >= 40 + (i) * (440 / l) && mx <= 40 + (i) * (440 / l) + (440 - l * 10) / l && grab == 1 && my >= 40 + (j) * (440 / m) && my <= 40 + (j) * (440 / m) + (440 - m * 10) / m && mp_s[i][j] == 2) {
				mp_s[i][j] = 0;
				break;
			}
		}
	}


}

void game(int l, int m) {

	// 背景の色を設定 | Set background color
	Scene::SetBackground(ColorF{ r1, g1, b1 });

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			mp[i][j] = l * j + i + 1;
		}
	}

	bool flag = 0;

	const Font font{ 50 };
	const Font f2{ 100 };
	const Font f3{ 80 };
	const Font f5{ 40 };
	const Font f6{ 30 };
	String text = U"";

	reset(l, m);

	int fontsize = 100;

	int x, y;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == l * m) {
				x = i + 1;
				y = j + 1;
			}
		}
	}



	while (System::Update())
	{
		Rect{ 30, 30, 10 + 110 * 4,10 + 110 * 4 }.draw(ColorF{ r2,g2,b2 });

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < m; j++) {

				if (mp_s[i][j] == 1) {
					if (mp[i][j] != -1) {
						text = U"{}"_fmt(mp[i][j]);
						Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }.draw(ColorF{ r3,g3,b3 });
						if (l == 6) f6(text).drawAt(Vec2(40 + (440 - l * 10) / l / 2 + i * (440 / l), 40 + (440 - m * 10) / m / 2 + j * (440 / m)), ColorF{ 0.25 });
					}
					else {
						Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }.draw(ColorF{ r3 * 0.7,g3 * 0.7,b3 * 0.7 });
					}

				}
				else if (mp_s[i][j] == 0) {
					Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }.draw(ColorF{ r3 * 0.5,g3 * 0.5,b3 * 0.5 });
				}
				else if (mp_s[i][j] == 2) {
					Rect{ 40 + (i) * (440 / l), 40 + (j) * (440 / m), (440 - l * 10) / l, (440 - m * 10) / m }.draw(ColorF{ r3 * 0.3,g3 * 0.3,b3 * 0.3 });
				}
			}

		}

		c_lclick(l, m);

		c_rclick(l, m);


		int sflag = 1;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] != l * j + i + 1) sflag = 0;
			}
		}

		if (SimpleGUI::Button(U"back", Vec2{ 20, 500 }, 100))
		{
			flag2 = 1;
			return;
		}

		if (sflag == 1) {

			if (KeyR.pressed() && flag == 0) {

				reset(l, m);

				for (int i = 0; i < l; i++) {
					for (int j = 0; j < m; j++) {
						if (mp[i][j] == l * m) {
							x = i + 1;
							y = j + 1;
						}
					}
				}
			}

			if (SimpleGUI::Button(U"RESTART!!", Vec2{ 640, 240 }))
			{
				reset(l, m);

				for (int i = 0; i < l; i++) {
					for (int j = 0; j < m; j++) {
						if (mp[i][j] == l * m) {
							x = i + 1;
							y = j + 1;
						}
					}
				}
			}

			text = U"CLEAR!!";
			font(text).drawAt(Vec2(640, 320), ColorF{ 0.25 });
		}

	}

}

void g_option() {//オプション中での操作

	const Font font{ 30 };

	String text;


	while (System::Update())
	{
		font(text).drawAt(Vec2(400, 150), ColorF{ Palette::Black });

		if (SimpleGUI::Button(U"background", Vec2{ 500, 100 }, 150))
		{
			flag2 = 8;
			return;
		}

		if (SimpleGUI::Button(U"盤面", Vec2{ 500, 200 }, 150))
		{
			flag2 = 9;
			return;
		}

		if (SimpleGUI::Button(U"パネル", Vec2{ 500, 300 }, 150))
		{
			flag2 = 10;
			return;
		}

		if (SimpleGUI::Button(U"リセット", Vec2{ 500, 400 }, 150))
		{
			flag2 = 11;
			return;
		}


		if (SimpleGUI::Button(U"back", Vec2{ 20, 500 }, 100))
		{
			flag2 = 1;
			return;
		}
	}
}

void reset_c() {//色を初期設定に戻す。

	r1 = 0.8, g1 = 0.9, b1 = 1.0;
	r2 = 0.6, g2 = 0.27, b2 = 0.0;
	r3 = 1.0, g3 = 0.7, b3 = 0.02;

	flag2 = 1;

}

void ch_color(double r, double g, double b, int type) {//色を変える関数

	const Font font{ 30 };

	String text;

	double x1 = 60 + 600 * r;
	double x2 = 60 + 600 * g;
	double x3 = 60 + 600 * b;

	bool grab = 0;

	while (System::Update())
	{

		int ra = r * 255;
		int ga = g * 255;
		int ba = b * 255;

		text = U"{} {} {}"_fmt(ra, ga, ba);

		font(text).drawAt(Vec2(600, 500), ColorF{ Palette::Black });

		Scene::SetBackground(ColorF{ r, g, b });


		double mx = Cursor::Pos().x;
		double my = Cursor::Pos().y;

		Rect{ 60, 80, 600, 20 }.draw(Palette::Black);

		Rect{ 60, 200, 600, 20 }.draw(Palette::Black);

		Rect{ 60, 320, 600, 20 }.draw(Palette::Black);

		Circle{ x1, 90, 40 }.draw(Palette::Black);

		Circle{ x2, 210, 40 }.draw(Palette::Black);

		Circle{ x3, 330, 40 }.draw(Palette::Black);

		Circle{ x1, 90, 35 }.draw();

		Circle{ x2, 210, 35 }.draw();

		Circle{ x3, 330, 35 }.draw();


		if (MouseL.pressed())  grab = 1;

		else grab = 0;


		if (grab) {

			if ((mx - x1) * (mx - x1) + (my - 90) * (my - 90) <= 1600) {
				if (mx <= 660 && mx >= 60) x1 = mx;
				r = (x1 - 60) / 600;
			}


			if ((mx - x2) * (mx - x2) + (my - 210) * (my - 210) <= 1600) {
				if (mx <= 660 && mx >= 60) x2 = mx;
				g = (x2 - 60) / 600;
			}


			if ((mx - x3) * (mx - x3) + (my - 330) * (my - 330) <= 1600) {
				if (mx <= 660 && mx >= 60) x3 = mx;
				b = (x3 - 60) / 600;
			}

		}

		if (type == 1) {
			r1 = r;
			g1 = g;
			b1 = b;
		}

		if (type == 2) {
			r2 = r;
			g2 = g;
			b2 = b;
		}

		if (type == 3) {
			r3 = r;
			g3 = g;
			b3 = b;
		}

		if (SimpleGUI::Button(U"back", Vec2{ 20, 500 }, 100))
		{
			flag2 = 1;
			return;
		}

	}
}

void Main() {

	Window::SetTitle(U"マインスイーパー");

	Scene::SetBackground(Palette::White);

	const Font font{ 100 };
	String text = U"";

	while (System::Update())
	{

		if (flag2 == 6) game(6, 6);
		if (flag2 == 7) g_option();
		if (flag2 == 8) ch_color(r1, g1, b1, 1);
		if (flag2 == 9) ch_color(r2, g2, b2, 2);
		if (flag2 == 10) ch_color(r3, g3, b3, 3);
		if (flag2 == 11) reset_c();

		if (flag2 == 0) {
			text = U"マインスイーパー";
			font(text).drawAt(Vec2(400, 240), ColorF{ Palette::Black });

			if (SimpleGUI::Button(U"START!!", Vec2{ 300, 340 }, 200))
			{
				flag2 = 1;
			}
		}

		if (flag2 == 1) {

			Scene::SetBackground(Palette::White);

			text = U"Mode Select";
			font(text).drawAt(Vec2(400, 150), ColorF{ Palette::Black });

			if (SimpleGUI::Button(U"6×6", Vec2{ 100, 480 }, 200))
			{
				flag2 = 6;
			}


			if (SimpleGUI::Button(U"option", Vec2{ 500, 480 }, 200))
			{
				flag2 = 7;
			}

		}

	}

}
