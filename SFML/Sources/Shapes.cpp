#include "../Headers/Shapes.h"

// Functions
void PrintRectangle(RectangleShape& rect,
	const Vector2f& pos, const Vector2f& size) {
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(Color::Green);

}


void EmptyBox(RectangleShape& rect, const Vector2f& pos,
	const Vector2f& size) {

	rect.setPosition(pos);
	rect.setSize(size);
	rect.setOutlineThickness(2);
	rect.setOutlineColor(Color::White);
	rect.setFillColor(Color::Transparent);

}

void CreateText(Text& text, const Vector2f& pos, const Font& font,
	const string& str, size_t font_size) {

	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(font_size);
	text.setFillColor(sf::Color::White);
	text.setPosition( 10 + pos.x, 10 + pos.y);
}

RectangleShape CreateFrame(const Vector2f& pos, const Vector2f& size) {
	RectangleShape rect(size);
	rect.setPosition(pos);
	rect.setFillColor(Color::Transparent);
	rect.setOutlineColor(Color::Yellow);
	rect.setOutlineThickness(2);
	return rect;
}


// Class TextBox

TextBox::TextBox(const RectangleShape& rect, const Text& text)
	: rect(rect)
	, text(text)
{

}

void TextBox::Draw(RenderWindow& window) const {
	window.draw(rect);
	window.draw(text);
}

const RectangleShape& TextBox::GetRect() const {
	return rect;
}

RectangleShape& TextBox::GetRect() {
	return rect;
}

const Text& TextBox::GetText() const {
	return text;
}

Text& TextBox::GetText() {
	return text;
}


// Struct Info

TB_Info::TB_Info(const Vector2f& pos, const Vector2f& size,
	 size_t font_size)
	: pos(pos)
	, size(size)
	, font_size(font_size)
{

}




