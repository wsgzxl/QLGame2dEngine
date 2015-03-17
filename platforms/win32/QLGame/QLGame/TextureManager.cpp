//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************

#include "TextureManager.h"

TextureManager* TextureManager::m_inst(0);

TextureManager* TextureManager::Inst()
{
	if(!m_inst)
		m_inst = new TextureManager();

	return m_inst;
}

TextureManager::TextureManager()
{
	// call this ONLY when linking with FreeImage as a static library
	#ifdef FREEIMAGE_LIB
		FreeImage_Initialise();
	#endif
}

//these should never be called
//TextureManager::TextureManager(const TextureManager& tm){}
//TextureManager& TextureManager::operator=(const TextureManager& tm){}
	
TextureManager::~TextureManager()
{
	// call this ONLY when linking with FreeImage as a static library
	#ifdef FREEIMAGE_LIB
		FreeImage_DeInitialise();
	#endif

	UnloadAllTextures();
	m_inst = 0;
}

bool TextureManager::LoadTexture(const char* filename, const unsigned int texID, GLenum image_format, GLint internal_format, GLint level, GLint border)
{
	GLuint tex = 0;  
    int tmp_bit;  
    int i;  
    int w, h;  
    int bpp;  
    unsigned char *bits = NULL;  
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;  
    FIBITMAP *bitmap = NULL;  
    GLBITMAP *glbmp = NULL;  
  
    fif = FreeImage_GetFileType(filename, 0);  
    if ( FIF_UNKNOWN == fif ) {  
        fif = FreeImage_GetFIFFromFilename(filename);  
        if ( FIF_UNKNOWN == fif )  
            return 0;     
    }  
    if ( FreeImage_FIFSupportsReading(fif) )   
        bitmap = FreeImage_Load(fif, filename, 0);  
      
    if ( !bitmap )   
        return 0;  
  
    printf("bit: %d\n", FreeImage_GetBPP(bitmap));  
  
    glbmp = FIBitmap2GLBitmap(bitmap);  
    if ( !glbmp )  
        return 0;  
  
    glGenTextures(1, &tex);  
    glBindTexture(GL_TEXTURE_2D, tex);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  
    glTexImage2D(GL_TEXTURE_2D, 0, glbmp->rgb_mode, glbmp->w, glbmp->h, 0, glbmp->rgb_mode, GL_UNSIGNED_BYTE, glbmp->buf);  
      
	FreeGLBitmap(glbmp);
    FreeImage_Unload(bitmap);     
  
    return tex;  
}
GLBITMAP* TextureManager::FIBitmap2GLBitmap(FIBITMAP *fibmp)  
{  
    int i, j, k;  
    int pitch = FreeImage_GetPitch(fibmp);  
    unsigned char *bits = FreeImage_GetBits(fibmp);  
    int bpp = FreeImage_GetBPP(fibmp);  
    GLBITMAP *glbmp = (GLBITMAP *)malloc(sizeof(GLBITMAP));   
    RGBQUAD *palette = NULL;  
  
    if ( !glbmp ) return NULL;  
      
    glbmp->w = FreeImage_GetWidth(fibmp);  
    glbmp->h = FreeImage_GetHeight(fibmp);     
  
    switch ( bpp ) {  
    case 8:  
        if ( !(palette = FreeImage_GetPalette(fibmp)) ) return NULL;   
        if ( !(glbmp->buf = (unsigned char *)malloc(glbmp->w*glbmp->h*3)) ) return NULL;  
        glbmp->rgb_mode = GL_RGB;  
        for ( i = 0; i < glbmp->h; ++i ) {  
            for ( j = 0; j < glbmp->w; ++j ) {  
                k = bits[i*pitch+j];  
                glbmp->buf[(i*glbmp->w+j)*3+0] = palette[k].rgbRed;  
                glbmp->buf[(i*glbmp->w+j)*3+1] = palette[k].rgbGreen;  
                glbmp->buf[(i*glbmp->w+j)*3+2] = palette[k].rgbBlue;  
            }  
        }  
        break;  
    case 24:  
        if ( !(glbmp->buf = (unsigned char *)malloc(glbmp->w*glbmp->h*3)) ) return NULL;  
        glbmp->rgb_mode = GL_RGB;  
        for ( i = 0; i < glbmp->h; ++i ) {  
            for ( j = 0; j < glbmp->w; ++j ) {  
                glbmp->buf[(i*glbmp->w+j)*3+0] = bits[i*pitch+j*3+2];  
                glbmp->buf[(i*glbmp->w+j)*3+1] = bits[i*pitch+j*3+1];  
                glbmp->buf[(i*glbmp->w+j)*3+2] = bits[i*pitch+j*3+0];  
            }  
        }  
        break;  
    case 32:  
        if ( !(glbmp->buf = (unsigned char *)malloc(glbmp->w*glbmp->h*4)) ) return NULL;  
        glbmp->rgb_mode = GL_RGBA;  
        for ( i = 0; i < glbmp->h; ++i ) {  
            for ( j = 0; j < glbmp->w; ++j ) {  
                glbmp->buf[(i*glbmp->w+j)*4+0] = bits[i*pitch+j*4+2];  
                glbmp->buf[(i*glbmp->w+j)*4+1] = bits[i*pitch+j*4+1];  
                glbmp->buf[(i*glbmp->w+j)*4+2] = bits[i*pitch+j*4+0];  
                glbmp->buf[(i*glbmp->w+j)*4+3] = bits[i*pitch+j*4+3];  
            }  
        }  
        break;  
    default: return NULL;     
    }  
  
    return glbmp;  
}  
bool TextureManager::UnloadTexture(const unsigned int texID)
{
	bool result(true);
	//if this texture ID mapped, unload it's texture, and remove it from the map
	if(m_texID.find(texID) != m_texID.end())
	{
		glDeleteTextures(1, &(m_texID[texID]));
		m_texID.erase(texID);
	}
	//otherwise, unload failed
	else
	{
		result = false;
	}

	return result;
}
void TextureManager::FreeGLBitmap(GLBITMAP *glbmp)  
{  
    if ( glbmp ) {  
        if ( glbmp->buf ) free(glbmp->buf);  
        free(glbmp);  
    }  
}  
bool TextureManager::BindTexture(const unsigned int texID)
{
	bool result(true);
	//if this texture ID mapped, bind it's texture as current
	if(m_texID.find(texID) != m_texID.end())
		glBindTexture(GL_TEXTURE_2D, m_texID[texID]);
	//otherwise, binding failed
	else
		result = false;

	return result;
}

void TextureManager::UnloadAllTextures()
{
	//start at the begginning of the texture map
	std::map<unsigned int, GLuint>::iterator i = m_texID.begin();

	//Unload the textures untill the end of the texture map is found
	while(i != m_texID.end())
		UnloadTexture(i->first);

	//clear the texture map
	m_texID.clear();
}