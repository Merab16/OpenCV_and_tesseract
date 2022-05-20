#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace sf;
using namespace std;



class TextBox {

private:
	RectangleShape rect;
	Text text;


public:

	TextBox(const RectangleShape& rect, const Text& text);

	void Draw(RenderWindow& window) const;

	const RectangleShape& GetRect() const;
	RectangleShape& GetRect();

	const Text& GetText() const;
	Text& GetText();



};

struct TB_Info {

	Vector2f pos;
	Vector2f size;
	size_t font_size;


	TB_Info(const Vector2f& pos, const Vector2f& size,
		size_t font_size);

};



void PrintRectangle(RectangleShape& rect, const Vector2f& pos,
	const Vector2f& size);


void EmptyBox(RectangleShape& rect, const Vector2f& pos,
	const Vector2f& size);

void CreateText(Text& text, const Vector2f& pos, const Font& font,
	const string& str, size_t font_size);

RectangleShape CreateFrame(const Vector2f& pos, const Vector2f& size);











