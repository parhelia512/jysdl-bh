﻿#pragma once
#include "SDL3/SDL.h"

struct Prop
{
    SDL_PropertiesID id_;

    Prop() { id_ = SDL_CreateProperties(); }

    ~Prop() { SDL_DestroyProperties(id_); }

    SDL_PropertiesID id() { return id_; }

    bool set(const char* name, void* value) { return SDL_SetPointerProperty(id_, name, value); }

    bool set(const char* name, const char* value) { return SDL_SetStringProperty(id_, name, value); }

    bool set(const char* name, int64_t value) { return SDL_SetNumberProperty(id_, name, value); }

    bool set(const char* name, int value) { return SDL_SetNumberProperty(id_, name, value); }

    bool set(const char* name, float value) { return SDL_SetFloatProperty(id_, name, value); }

    bool set(const char* name, bool value) { return SDL_SetBooleanProperty(id_, name, value); }
};

bool KeyFilter(void* data, SDL_Event* event);
int InitSDL(void);
int ExitSDL(void);
Uint32 ConvertColor(Uint32 color);
int InitGame(void);
int ExitGame(void);
int RenderToTexture(SDL_Texture* src, SDL_FRect* src_rect, SDL_Texture* dst, SDL_FRect* dst_rect, double angle, SDL_FPoint* center, SDL_FlipMode filp);
SDL_Texture* CreateRenderedTexture(SDL_Texture* ref);
SDL_Texture* CreateRenderedTexture(int w, int h);
int JY_LoadPicture(const char* str, int x, int y);
int JY_ShowSurface(int flag);
int JY_ShowSlow(int delaytime, int Flag);
int JY_Delay(int x);
double JY_GetTime();
int JY_PlayMIDI(const char* filename);
int StopMIDI();
int JY_PlayWAV(const char* filename);
int JY_GetKey(int* key, int* type, int* mx, int* my);
int JY_GetKeyState(int key);
int JY_SetClip(int x1, int y1, int x2, int y2);
int JY_DrawRect(int x1, int y1, int x2, int y2, int color);
void HLine32(int x1, int x2, int y, int color);
void VLine32(int x1, int x2, int y, int color);
int JY_FillColor(int x1, int y1, int x2, int y2, int color);
int JY_Background(int x1, int y1, int x2, int y2, int Bright, int color);
int JY_PlayMPEG(char* filename, int esckey);
int JY_FullScreen();
int JY_SaveSur(int x, int y, int w, int h);
int JY_LoadSur(int id, int x, int y);
int JY_FreeSur(int id);

SDL_Rect RotateRect(const SDL_Rect* rect);
SDL_Rect RotateReverseRect(const SDL_Rect* rect);
