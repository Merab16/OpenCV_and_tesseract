#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;


struct MyImg {

	Image image;
	Texture texture;
	Sprite sprite;
	string category;

	MyImg(const string& categ, const Vector2f& pos);

	//~MyImg();

};

struct MI_Info {

	Vector2f pos;

	MI_Info(const Vector2f& pos);
};


