//#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
 

//SDL.h中已有main函数 在这里重载main函数
int main(int argc, char* args[])
{
    //窗口
    SDL_Window* window = nullptr;
 
    //窗口的表面
    SDL_Surface* bmp = nullptr;

    //渲染器
    SDL_Renderer* ren=nullptr;

    //材质
    SDL_Texture *tex = nullptr;

    //初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return -1;
    }
 
    //创建窗口
  window = SDL_CreateWindow("KOF", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (nullptr == window)
    {
        SDL_Quit();
        return -1;
    }
 
    //创建渲染器
    ren = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr)
    {
        return -1;
    }

    //加载窗体图标
    SDL_Surface *iconSurface = IMG_Load("Image/Hero/athena.jpg");
    if (iconSurface == NULL) return -1;
    SDL_SetWindowIcon(window, iconSurface);

    //创建表面
    bmp = IMG_Load("Image/Bg/mainBg.png");
    if(bmp == nullptr)
    {
        return -1;
    }

    //创建材质
    tex = SDL_CreateTextureFromSurface(ren,bmp);
    if(tex == nullptr)
    {
        return -1;
    }

    //清空渲染器
    SDL_RenderClear(ren);
    //将材质复制到渲染器
    SDL_RenderCopy(ren, tex, NULL, NULL);
    //呈现渲染器
    SDL_RenderPresent(ren);
    //更新表面
    SDL_UpdateWindowSurface(window);
    
     //等待两秒
    SDL_Delay(2000);

    //释放资源
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(bmp);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
 
    //退出SDL子系统
    SDL_Quit();
    return 0;
}
