#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "fssimplewindow.h"
#include "yssimplesound.h"
#include "yspng.h"
#include <string>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <cstring>
#include <sstream>

std::string to_string(double x)
{
  std::ostringstream ss;
  ss << x;
  return ss.str();
}

int main(void)
{
    double total_time =0.0;
    YsSoundPlayer player;
    YsSoundPlayer::SoundData wav;
    
    YsRawPngDecoder background;
    YsRawPngDecoder tile1;
    YsRawPngDecoder tile2;
    YsRawPngDecoder tile3;
    YsRawPngDecoder tree;
    YsRawPngDecoder bush1;
    YsRawPngDecoder bush2;
    YsRawPngDecoder skeleton;
    YsRawPngDecoder kunai;
    
  
    background.Decode("BG.png");
    background.Flip();
    tile1.Decode("tile (1).png");
    tile1.Flip();
    tile2.Decode("tile (2).png");
    tile2.Flip();
    tile3.Decode("tile (3).png");
    tile3.Flip();
    tree.Decode("Tree.png");
    tree.Flip();
    bush1.Decode("Bush (1).png");
    bush1.Flip();
    bush2.Decode("Bush (2).png");
    bush2.Flip();
    skeleton.Decode("Skeleton.png");
    skeleton.Flip();
    kunai.Decode("Kunai.png");
    kunai.Flip();
    int kunai_x = 877;
    int kunai_x1 = 877;
    int kunai_y = 457;
    
    //Girl Ideal Character Declaration and Initialization
    YsRawPngDecoder girl_ideal[10];
    int girl_y = 0;
    int girlj_y = 500;
    int girl_x = 140;
    for (int i=0; i <10; ++i)
    {
        std::string str = "Girl_Idle__00" + std::to_string(i)+".png";
        
        girl_ideal[i].Decode(str.c_str());
        girl_ideal[i].Flip();
    }
    double girl_ideal_start_time1 = 6.5;
    double girl_ideal_start_time2 = 180;
    double girl_ideal_start_time3 = 180;
    double girl_ideal_start_time4 = 180;
    int girl_ideal_position1 = 0;
    //Ideal Character Declaration and Initialization
    
    //Girl Dead Character Declaration and Initialization
    YsRawPngDecoder girl_dead[10];

    for (int i=0; i <10; ++i)
    {
        std::string str = "Girl_Dead__00" + std::to_string(i)+".png";
        
        girl_dead[i].Decode(str.c_str());
        girl_dead[i].Flip();
    }
    double girl_dead_start_time1 = 180;
    int girl_dead_position1 = 0;
    //Ideal Character Declaration and Initialization

    //Girl Attack Character Declaration and Initialization
    YsRawPngDecoder girl_attack[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Girl_Attack__00" + std::to_string(i)+".png";
        
        girl_attack[i].Decode(str.c_str());
        girl_attack[i].Flip();
    }
    double girl_attack_start_time1 = 180;
    double girl_attack_start_time2 = 180;
    int girl_attack_position1 = 0;
    //Attack Character Declaration and Initialization
    
    //Nina Glide Character Declaration and Initialization
    YsRawPngDecoder ninja_glide[10];
    int ninja_y = 0;
    int ninja_x = 820;
    for (int i=0; i <10; ++i)
    {
        std::string str = "Ninja_Glide_00" + std::to_string(i)+".png";
        
        ninja_glide[i].Decode(str.c_str());
        ninja_glide[i].Flip();
    }
    double ninja_glide_start_time1 = 13.5;
    int ninja_glide_position1 = 0;
    //Ninja Glide Character Declaration and Initialization
    
    //Nina Ideal Character Declaration and Initialization
    YsRawPngDecoder ninja_ideal[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Ninja_Idle__00" + std::to_string(i)+".png";
        
        ninja_ideal[i].Decode(str.c_str());
        ninja_ideal[i].Flip();
    }
    double ninja_ideal_start_time1 = 180;
    int ninja_ideal_position1 = 0;
    //Ninja Ideal Character Declaration and Initialization
    
    //Nina throw Character Declaration and Initialization
    YsRawPngDecoder ninja_throw[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Ninja_Throw__00" + std::to_string(i)+".png";
        
        ninja_throw[i].Decode(str.c_str());
        ninja_throw[i].Flip();
    }
    double ninja_throw_start_time1 = 30;
    int ninja_throw_position1 = 0;
    //Ninja Ideal Character Declaration and Initialization
    
    //Girl Jump Character Declaration and Initialization
    YsRawPngDecoder girl_jump[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Girl_Jump__00" + std::to_string(i)+".png";
        
        girl_jump[i].Decode(str.c_str());
        girl_jump[i].Flip();
    }
    double girl_jump_start_time1 = 180;
    int girl_jump_position1 = 0;
    //Girl Jump Character Declaration and Initialization
    
    //Girl Run Character Declaration and Initialization
    YsRawPngDecoder girl_run[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Girl_Run__00" + std::to_string(i)+".png";
        
        girl_run[i].Decode(str.c_str());
        girl_run[i].Flip();
    }
    double girl_run_start_time1 = 38;
    double girl_run_start_time2 = 180;
    int girl_run_position1 = 0;
    //Girl Run Character Declaration and Initialization
    
    //Ninja Run Character Declaration and Initialization
    YsRawPngDecoder ninja_run[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Ninja_Run__00" + std::to_string(i)+".png";
        
        ninja_run[i].Decode(str.c_str());
        ninja_run[i].Flip();
    }
    double ninja_run_start_time1 = 38;
    double ninja_run_start_time2 = 180;
    int ninja_run_position1 = 0;
    //Ninja Run Character Declaration and Initialization
    
    //Ninja Slide Character Declaration and Initialization
    YsRawPngDecoder ninja_slide[10];
    for (int i=0; i <10; ++i)
    {
        std::string str = "Ninja_Slide__00" + std::to_string(i)+".png";
        
        ninja_slide[i].Decode(str.c_str());
        ninja_slide[i].Flip();
    }
    double ninja_slide_start_time1 = 180;
    int ninja_slide_position1 = 0;
    //Ninja Slide Character Declaration and Initialization
    

    if(YSOK!=wav.LoadWav("Helios.wav"))
    {
        printf("Failed to read %s\n","o4cdefgab.wav");
        return 1;
    }
    FsOpenWindow(0,0,1024,585,1);
    FsChangeToProgramDir();
    

    glShadeModel(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    player.Start();
    player.PlayOneShot(wav);
    
    int key = FSKEY_NULL;
    int lb,mb,rb,mx,my;
    FsPassedTime();
    while(YSTRUE==player.IsPlaying(wav) && FSKEY_ESC != key)
    {
        auto millisec=FsPassedTime();
        double dt=(double)millisec/1000.0;
        total_time += dt; //total time n seconds
        
//        Print the position of the mouse just to make it easy to find screen co-ordinates while drawing other assets
        if(FSMOUSEEVENT_MOVE == FsGetMouseEvent(lb,mb,rb,mx,my))
            {
                    if(mx<1025 && my<584)
                    {
                        printf("%d %d \n", mx, my);
                    }

            }
        player.KeepPlaying();
        FsPollDevice();
        key =FsInkey();
        
     
        
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        //Draw here//
        
        //Draw background
        if (total_time>0.0)
        {glRasterPos2i(0,584);
        glDrawPixels(background.wid,background.hei,GL_RGBA,GL_UNSIGNED_BYTE,background.rgba);
        }
        
        //Draw tile1
        if (total_time >=1 )
        {
            glRasterPos2i(50,584);
            glDrawPixels(tile1.wid,tile1.hei,GL_RGBA,GL_UNSIGNED_BYTE,tile1.rgba);
        }
//        Draw tile2
        double n_times = (total_time-0.5);
        if (total_time >=1.5 )
        {
            double n_times = 3*(total_time-0.5);
            for (int i = 1; i<n_times; i++)
            {
            glRasterPos2i(50+i*95,584);
            glDrawPixels(tile2.wid,tile2.hei,GL_RGBA,GL_UNSIGNED_BYTE,tile2.rgba);
            if(n_times>9)
            {
                n_times =9;
            }
            }
        }
        
        //Draw tile3
        if (total_time >3.9 )
        {
            glRasterPos2i(50+95*9,584);
            glDrawPixels(tile3.wid,tile3.hei,GL_RGBA,GL_UNSIGNED_BYTE,tile3.rgba);
        }
        
        //Draw Tree
        if (total_time>4.5)
        {
        glRasterPos2i(750,495);
        glDrawPixels(tree.wid,tree.hei,GL_RGBA,GL_UNSIGNED_BYTE,tree.rgba);
        }
        
        //Draw bushes
        if (total_time>5)
        {
        glRasterPos2i(910,495);
        glDrawPixels(bush2.wid,bush2.hei,GL_RGBA,GL_UNSIGNED_BYTE,bush2.rgba);
        }
        if (total_time>5.5)
        {
        glRasterPos2i(85,495);
        glDrawPixels(bush1.wid,bush1.hei,GL_RGBA,GL_UNSIGNED_BYTE,bush1.rgba);
        }
        if (total_time>6)
        {
        glRasterPos2i(500,495);
        glDrawPixels(skeleton.wid,skeleton.hei,GL_RGBA,GL_UNSIGNED_BYTE,skeleton.rgba);
        }
        
        
        //Draw Girl Ideal_character
        if (total_time> 6.5 && girl_y <= 490)
        {
            double time_elapsed;
            time_elapsed = total_time - girl_ideal_start_time1;
            if (time_elapsed >=0.05)
            {
                girl_ideal_start_time1+=0.05;
                ++girl_ideal_position1;
            }
            if (girl_ideal_position1>9)
            {
                girl_ideal_position1 = 0;
            }
//            printf("%f %f \n", ideal_start_time, total_time);
            glRasterPos2i(girl_x,girl_y);
            glDrawPixels(girl_ideal[girl_ideal_position1].wid,girl_ideal[girl_ideal_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_ideal[girl_ideal_position1].rgba);
            if (girl_y <= 490)
            {
                girl_y+=10;
                if (girlj_y>490)
                {
                    girl_dead_start_time1 = total_time;
                }
            }
            
        }
        
        //Draw Girl Dead_character
        if (total_time> girl_dead_start_time1 && girl_dead_position1<=9)
        {
            double time_elapsed;
            time_elapsed = total_time - girl_dead_start_time1;
            if (time_elapsed >=0.05)
            {
                girl_dead_start_time1+=0.05;
                ++girl_dead_position1;
            }
            if (girl_dead_position1>9)
            {
//                girl_dead_position1 = 0;
                girl_ideal_start_time2 = total_time;
            }
            glRasterPos2i(girl_x,girl_y+20);
            glDrawPixels(girl_dead[girl_dead_position1].wid,girl_dead[girl_dead_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_dead[girl_dead_position1].rgba);
        }
        
        //Draw Girl Ideal_character2
        if ((total_time> girl_ideal_start_time2 && total_time <girl_attack_start_time1) || (total_time >girl_ideal_start_time3 && total_time <girl_attack_start_time2) || (total_time>girl_ideal_start_time4 && total_time<girl_ideal_start_time4+2))
        {
            double time_elapsed;
            time_elapsed = total_time - girl_ideal_start_time1;
            if (time_elapsed >=0.05)
            {
                girl_ideal_start_time1+=0.05;
                ++girl_ideal_position1;
            }
            if (girl_ideal_position1>9)
            {
                girl_ideal_position1 = 0;
            }
            glRasterPos2i(girl_x,girl_y);
            glDrawPixels(girl_ideal[girl_ideal_position1].wid,girl_ideal[girl_ideal_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_ideal[girl_ideal_position1].rgba);

            }
        //Draw dialogues
        if (total_time>8.5 && total_time<8.5+1)
        {
        glColor3f(1,1,1);
        glRasterPos2i(girl_x,girl_y-120);
        YsGlDrawFontBitmap12x16("Oouuchhh!! Oops I fell!!");
        }
        if (total_time>9.5 && total_time<9.5+2)
        {
        glColor3f(1,1,1);
        glRasterPos2i(girl_x,girl_y-120);
        YsGlDrawFontBitmap12x16("Wooooww!!!");
        }
        if (total_time>9.5+2 && total_time<9.5+2+2)
        {
        glColor3f(1,1,1);
        glRasterPos2i(girl_x,girl_y-120);
        YsGlDrawFontBitmap12x16("Where am I???");
        }
        if (total_time>20+2 && total_time<20+4)
        {
        glColor3f(1,1,1);
        glRasterPos2i(girl_x,girl_y-120);
        YsGlDrawFontBitmap12x16("Heyy!! Do you know where we are???");
        }
        if (total_time>20+4 && total_time<20+6)
        {
        glColor3f(1,1,1);
        glRasterPos2i(ninja_x,ninja_y-120);
        YsGlDrawFontBitmap12x16("I don't know");
        }
        if (total_time>20 && total_time<30)
        {
        glColor3f(0,1,0);
        glRasterPos2i(55,450);
        YsGlDrawFontBitmap16x20("SAKURA");
        }
        if (total_time>20 && total_time<30)
        {
        glColor3f(0,1,0);
        glRasterPos2i(930,450);
        YsGlDrawFontBitmap16x20("SOJI");
        }
        //Draw Ninja Glide
        if (total_time> 13.5 && ninja_y <= 490)
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_glide_start_time1;
            if (time_elapsed >=0.05)
            {
                ninja_glide_start_time1+=0.05;
                ++ninja_glide_position1;
            }
            if (ninja_glide_position1>9)
            {
                ninja_glide_position1 = 0;
            }
            glRasterPos2i(ninja_x,ninja_y);
            glDrawPixels(ninja_glide[ninja_glide_position1].wid,ninja_glide[ninja_glide_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_glide[ninja_glide_position1].rgba);
            if (ninja_y <= 490)
            {
                ninja_y+=1;
                if(ninja_y > 490)
                {
                    ninja_ideal_start_time1 = total_time;

                }
            }
            
        }
        
        //Draw Ninja Ideal
        if ((total_time> ninja_ideal_start_time1 && total_time < 30) || (total_time> 30.2 && total_time < 33.3) || (total_time> 33.5 && total_time < 38))
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_ideal_start_time1;
            if (time_elapsed >=0.05)
            {
                ninja_ideal_start_time1+=0.05;
                ++ninja_ideal_position1;
            }
            if (ninja_ideal_position1>9)
            {
                ninja_ideal_position1 = 0;
            }
            glRasterPos2i(ninja_x+50,ninja_y);
            glDrawPixels(ninja_ideal[ninja_ideal_position1].wid,ninja_ideal[ninja_ideal_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_ideal[ninja_ideal_position1].rgba);
        }
        
        // Draw Fihgt!!
        if (total_time >26 && total_time < 27)
        {
            glColor3f(1,0,0);
            glRasterPos2i(490,190);
            YsGlDrawFontBitmap32x48("3");
        }
        if (total_time >27 && total_time < 28)
        {
            glColor3f(1,0,0);
            glRasterPos2i(490,190);
            YsGlDrawFontBitmap32x48("2");
        }
        if (total_time >28 && total_time < 29)
        {
            glColor3f(1,0,0);
            glRasterPos2i(490,190);
            YsGlDrawFontBitmap32x48("1");
        }
        if (total_time >29 && total_time < 30)
        {
            glColor3f(1,0,0);
            glRasterPos2i(420,190);
            YsGlDrawFontBitmap32x48("Fight!!");
        }
        
        //Draw Ninja throw
        if ((total_time> 30 && total_time<30.2) || (total_time> 33.3 && total_time<33.5))
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_throw_start_time1;
            if (time_elapsed >=1)
            {
                ninja_throw_start_time1+=1;
                ++ninja_throw_position1;
            }
            if (ninja_throw_position1>9)
            {
                ninja_throw_position1 = 0;
            }
            glRasterPos2i(ninja_x+50-18,ninja_y);
            glDrawPixels(ninja_throw[ninja_throw_position1].wid,ninja_throw[ninja_throw_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_throw[ninja_throw_position1].rgba);
        }
        //Draw kunai
        if (total_time> 30 && kunai_x > 210)
        {
            glRasterPos2i(kunai_x,kunai_y);
            glDrawPixels(kunai.wid,kunai.hei,GL_RGBA,GL_UNSIGNED_BYTE,kunai.rgba);
            if (kunai_x>210)
             {
                 kunai_x-=5;
                 if(kunai_x<=210)
                 {girl_attack_start_time1 = total_time;}
             }
            
        }
        
        if (total_time> 33.5 && kunai_x1 > 210)
        {
            glRasterPos2i(kunai_x1,kunai_y);
            glDrawPixels(kunai.wid,kunai.hei,GL_RGBA,GL_UNSIGNED_BYTE,kunai.rgba);
            kunai_x1-=6;
            if(kunai_x1<=210)
            {girl_attack_start_time2 = total_time;}
        }
        
        
        //Draw Girl attack
        if ((total_time> girl_attack_start_time1 && total_time < girl_ideal_start_time3))
        {
            double time_elapsed;
            time_elapsed = total_time - girl_attack_start_time1;
            if (time_elapsed >=0.05)
            {
                girl_attack_start_time1+=0.05;
                ++girl_attack_position1;
            }
            if (girl_attack_position1>9)
            {
                girl_attack_position1 = 0;
                girl_ideal_start_time3 = total_time;
            }
            glRasterPos2i(girl_x,girl_y+10);
            glDrawPixels(girl_attack[girl_attack_position1].wid,girl_attack[girl_attack_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_attack[girl_attack_position1].rgba);
        }
        if ((total_time> girl_attack_start_time2 && total_time < girl_ideal_start_time4 && total_time > girl_ideal_start_time3))
        {
            double time_elapsed;
            time_elapsed = total_time - girl_attack_start_time2;
            if (time_elapsed >=0.05)
            {
                girl_attack_start_time2+=0.05;
                ++girl_attack_position1;
            }
            if (girl_attack_position1>9)
            {
                girl_attack_position1 = 0;
                girl_ideal_start_time4 = total_time;
            }
            glRasterPos2i(girl_x,girl_y+10);
            glDrawPixels(girl_attack[girl_attack_position1].wid,girl_attack[girl_attack_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_attack[girl_attack_position1].rgba);
        }
        
        //Draw Girl run
        if ((total_time> girl_ideal_start_time4+2 && girl_x < 350))
        {
            double time_elapsed;
            time_elapsed = total_time - girl_run_start_time1;
            if (time_elapsed >=0.15)
            {
                girl_run_start_time1+=0.15;
                ++girl_run_position1;
            }
            if (girl_run_position1>9)
            {
                girl_run_position1 = 0;
            }
            glRasterPos2i(girl_x,girl_y);
            glDrawPixels(girl_run[girl_run_position1].wid,girl_run[girl_attack_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_run[girl_run_position1].rgba);
            girl_x++;
            if(girl_x>=350)
            {
                girl_jump_start_time1 = total_time;
            }
        }
        if (total_time>girl_run_start_time2 && total_time<50)
        {
            double time_elapsed;
            time_elapsed = total_time - girl_run_start_time2;
            if (time_elapsed >=0.05)
            {
                girl_run_start_time2+=0.05;
                ++girl_run_position1;
            }
            if (girl_run_position1>9)
            {
                girl_run_position1 = 0;
            }
            glRasterPos2i(girl_x,girl_y);
            glDrawPixels(girl_run[girl_run_position1].wid,girl_run[girl_attack_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_run[girl_run_position1].rgba);
            girl_x+=5;
        }
        
        //Draw Girl jump
        if ((total_time> girl_jump_start_time1 && girlj_y <=500))
        {
            double time_elapsed;
            time_elapsed = total_time - girl_jump_start_time1;
            if (time_elapsed >=0.15)
            {
                girl_jump_start_time1+=0.15;
                ++girl_jump_position1;
            }
            if (girl_jump_position1>9)
            {
                girl_jump_position1 = 0;
            }
            glRasterPos2i(girl_x,girlj_y);
            glDrawPixels(girl_jump[girl_jump_position1].wid,girl_jump[girl_jump_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,girl_jump[girl_jump_position1].rgba);
            girl_x++;
            if (girl_x<480)
            {
                girlj_y--;
            }
            else{
                girlj_y++;
                if(girlj_y>500){
                    girl_run_start_time2 =total_time;
                    ninja_run_start_time2 = total_time;
                }
                }
        }
        
        //Draw Ninja run
        if ((total_time> girl_ideal_start_time4+2 && girl_x < 350))
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_run_start_time1;
            if (time_elapsed >=0.15)
            {
                ninja_run_start_time1+=0.15;
                ++ninja_run_position1;
            }
            if (ninja_run_position1>9)
            {
                ninja_run_position1 = 0;
            }
            glRasterPos2i(ninja_x,ninja_y);
            glDrawPixels(ninja_run[ninja_run_position1].wid,ninja_run[ninja_run_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_run[ninja_run_position1].rgba);
            ninja_x--;
        }
        if (total_time>girl_run_start_time2 && total_time<50)
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_run_start_time2;
            if (time_elapsed >=0.05)
            {
                ninja_run_start_time2+=0.05;
                ++ninja_run_position1;
            }
            if (ninja_run_position1>9)
            {
                ninja_run_position1 = 0;
            }
            glRasterPos2i(ninja_x,ninja_y);
            glDrawPixels(ninja_run[ninja_run_position1].wid,ninja_run[ninja_run_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_run[ninja_run_position1].rgba);
            ninja_x-=5;
        }
        //Draw Ninja silde
        if ((total_time> girl_jump_start_time1 && total_time < girl_run_start_time2))
        {
            double time_elapsed;
            time_elapsed = total_time - ninja_slide_start_time1;
            if (time_elapsed >=0.15)
            {
                ninja_slide_start_time1+=0.15;
                ++ninja_slide_position1;
            }
            if (ninja_slide_position1>9)
            {
                ninja_slide_position1 = 0;
            }
            glRasterPos2i(ninja_x,ninja_y);
            glDrawPixels(ninja_slide[ninja_slide_position1].wid,ninja_slide[ninja_slide_position1].hei,GL_RGBA,GL_UNSIGNED_BYTE,ninja_slide[ninja_slide_position1].rgba);
            ninja_x--;
        }
        //Draw Ending
        if (total_time>46 && total_time<51)
        {
        glColor3f(0,1,0);
        glRasterPos2i(280,420);
        YsGlDrawFontBitmap16x20("No animated characters were hurt");
        glRasterPos2i(280,450);
        YsGlDrawFontBitmap16x20("during the making of this animation");
        }
        if (total_time>51 && total_time<56)
        {
        glColor3f(0,1,0);
        glRasterPos2i(280,420);
        YsGlDrawFontBitmap16x20("Sakura and Soji are good friends");
        glRasterPos2i(280,450);
        YsGlDrawFontBitmap16x20("They were just having a bit of fun!!");
        }
        if (total_time>56 && total_time<61)
        {
        glColor3f(0,1,0);
        glRasterPos2i(0,420);
        YsGlDrawFontBitmap16x20("All characters in this animation are fictional any resemblance");
        glRasterPos2i(0,450);
        YsGlDrawFontBitmap16x20("   to a person living or dead is purely coincidental :P");
        }
        if (total_time>61 && total_time<66)
        {
        glColor3f(0,1,0);
        glRasterPos2i(0,420);
        YsGlDrawFontBitmap16x20("     All weapons used in this animation are harmless");
        glRasterPos2i(0,450);
        YsGlDrawFontBitmap16x20("             they are just made up of Pixels");
        }
        if (total_time>66)
        {
        glRasterPos2i(0,450);
        YsGlDrawFontBitmap16x20("          Enjoy the music or press ESC to Exit");
        glColor3f(1,0,0);
        glRasterPos2i(380,165);
        YsGlDrawFontBitmap10x14("Written by: Karanveer Singh");
        glRasterPos2i(380,186);
        YsGlDrawFontBitmap10x14("Directed by: Karanveer Singh");
        glRasterPos2i(380,207);
        YsGlDrawFontBitmap10x14("Animated by: Karanveer Singh");
        }
  
        //Draw Timer on top right
        glColor3f(1,1,1);
        glRasterPos2i(960,10);
        std::string str = to_string(total_time);
        char digits[10];
        std::strcpy( digits, str.c_str() );
        YsGlDrawFontBitmap8x8(digits);
        
        FsSwapBuffers();
        FsSleep(1);
    }
    player.End();
    return 0;
}
