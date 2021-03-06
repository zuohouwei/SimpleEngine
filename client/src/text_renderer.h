#pragma once
//GLEW
#include <GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>

#include "core/shader.h"
#include "core/texture.h"
#include <map>

#include <freetype2/ft2build.h>
#include "animation/frame_animation.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_BBOX_H



class TextRenderer : public Singleton<TextRenderer>
{
public:
	struct FontGlyph
	{
		uint32_t CharCode;		// �ַ���
		uint32_t GlyphIndex;
		int Advance;
		int Left;
		int Top;
		int Width;
		int Height;
		Texture* Texture;
		bool IsEmotion;
		bool EmotionUpdated;
		FrameAnimation* Emotion;
		FontGlyph()
		{
			EmotionUpdated = false;
			CharCode = 0;
			GlyphIndex = 0;
			Advance = 0;
			IsEmotion = false;
			Emotion = nullptr;
			Texture = nullptr;
		}
	};

	
	enum Alighment
	{
		LEFT = 0,
		CENTER,
		RIGHT,
		TOP,
		BOTTOM
	};

	struct MeasureInfo
	{
		int Height;
		int Width;
		int LastLineWidth;
		int MaxWidth;
		int MaxHeight;
	};

public:
	
	TextRenderer();
	~TextRenderer();

	int MeasureRange(std::wstring text, int start,int end, bool showEmotion = false);
	
	MeasureInfo  MeasureText(std::wstring text, int bound_width, bool showEmotion = false);

	void RenderText(std::wstring text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	
	void RenderFontText(std::string path,std::wstring text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

	void RenderPlotText(std::wstring text, GLfloat x, GLfloat y);

	void DrawTextW(std::wstring text, int x, int y, Alighment align = LEFT, int bound_width = -1, glm::vec3 color = {1.f,1.f,1.f},bool showEmotion = false);

	void DrawTextC(const char* str, int x, int y, Alighment align = LEFT, int bound_width = -1, glm::vec3 color = { 1.f,1.f,1.f }, bool showEmotion =false);

	int GetFontHeight() { return m_FontHeight; }
private:
	void EnsureLoadText(std::vector<uint32_t> unicodes,bool showEmotion = false);
	void EnsureLoadText(std::wstring text, bool showEmotion  = false);
	
	int GetCharcode(const std::vector<uint32_t>& unicodes, size_t i, uint32_t& charcode, bool showEmotion = false);
	int GetCharcode(const std::wstring& text, size_t i,uint32_t& charcode, bool showEmotion = false);
	
	void DrawGlyphTexture(uint32_t id, float x,float y,float w,float h);

	bool LoadGlyph(uint32_t charcode,bool emotion = false);
	

	bool IsInRange(wchar_t c);

	FT_Library m_FtLib;

	FT_Face m_FtFace;

	bool m_bUseKerning;
	
	std::map<uint32_t, FontGlyph*> m_FontGlyphs;

	bool m_IsScaleable;
	
	int m_ScreeHeight;

	int m_BearingY;

	uint32_t m_FontSize;
	
	uint32_t m_FontHeight;
	
	GLuint VAO, VBO;

	Shader* m_pShader;

	std::vector<Texture*> m_FontTextures;

};

void luaopen_text_renderer(lua_State* L);