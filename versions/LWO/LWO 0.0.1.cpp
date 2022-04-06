#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "view.h"
#include <vector>
#include "stdafx.h"
#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <dis.h>
#include <dsi.h>
#include <split.h>
#include <Windows.h>
using namespace sf;

Sprite herosprite;
Sprite herosprites[3];
String File[3]{"main.png", "main2.png", "main3.png"};

Image i0; Image i1; Image i2; Texture t0; Texture t1; Texture t2;
			    

SOCKET Connection;

int online[3]{0, 0, 0};
int nidk1 = -1; //ur own index
int nidk2 = -1; //ur own online

#include "classes.h"

void ClientHandler() {
	char msg[256];
	while (true) {
	    recv(Connection, msg, sizeof(msg), 0);
	    
		string idk = msg;
		//std::cout << "IDK from somebody: " << idk << std::endl;
	    vector<string> idk0 = split(idk, ',');
	    //std::cout << idk0[0] << " " << idk0[1] << " " << idk0[2] << " " << idk0[3] << std::endl;
	    int tidk1; dsi(tidk1, idk0[0]); float idk1 = tidk1; //x
	    int tidk2; dsi(tidk2, idk0[1]); float idk2 = tidk2; //y
	    int idk3; dsi(idk3, idk0[2]); //index
	    int idk4; dsi(idk4, idk0[3]); //online

	    if (nidk1 == idk3) {
	    	std::cout << "ERROR\n"; system("pause");
	    }
		online[idk3] = idk4;
	    //std::cout << idk3 << " " << idk4 << "\n";
		if (online[idk3] == 1) {
			herosprites[idk3].setPosition(idk1, idk2);
		} else {
			Image imagez; Texture texturez;
			imagez.loadFromFile("off.png");
			texturez.loadFromImage(imagez);
			herosprites[idk3].setTexture(texturez);
			herosprites[idk3].setTextureRect(IntRect(0, 0, 25.0, 31.0)); //later we will get w and h from server!
		}
		//pnum = idk6
	    msg[256];
    }
}

int main() {
    #include "client.h"

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));
    
    Player p(500, 500, 25.0, 31.0);
    
	Other o(500, 500, 25.0, 31.0, 0);
    Other o1(900, 500, 25.0, 31.0, 1);
    Other o2(400, 500, 25.0, 31.0, 2);
    
    Image map_image;
	map_image.loadFromFile("map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
 
    float heroteleporttimer = 0; //создаем для примера телепортации героя через 3 секунды
    float CurrentFrame = 0;
	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 
 
    while (window.isOpen()) {
    	//std::cout << "NIDK1: " << nidk1 << std::endl;
    	//std::cout << "NIDK2: " << nidk2 << std::endl;
    	//std::cout << online[0] << online[1] << online[2] << std::endl;
    	
	    float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры
 
        heroteleporttimer += time;//прибавляем к нашей переменной time
 
        if (heroteleporttimer > 3000) {
		    //herosprite.setPosition(0, 120); heroteleporttimer = 0; //если таймер телепорта больше 3000 (это примерно 3 секунды), то телепортируем героя и обнуляем таймер телепортации
		}
 
 
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        
        #include "keys.h"

        p.update(time);
        //for (int pl=0; pl<3; pl++) {
        	//if (online[pl] == 0) {
        	//	Image imagez; Texture texturez;
			//    imagez.loadFromFile("off.png");
			//    texturez.loadFromImage(imagez);
			//    herosprites[pl].setTexture(texturez);
			//    herosprites[pl].setTextureRect(IntRect(0, 0, 25.0, 31.0)); //later we will get w and h from server!
			//} else {
			//	Image imagez; Texture texturez;
			//    imagez.loadFromFile(File[pl]);
			//    texturez.loadFromImage(imagez);
			//    herosprites[pl].setTexture(texturez);
			//    herosprites[pl].setTextureRect(IntRect(0, 0, 25.0, 31.0)); //later we will get w and h from server!
		//	}
        //}
        //o.update(time);
        //std::cin.getline(msg1, sizeof(msg1));
        
        std::string strax;
        dis(strax, p.x);
        std::string stray;
        dis(stray, p.y);
        //std::string snum;
        //dis(snum, p.mynumber);
        std::string straindex;
        dis(straindex, nidk1);
        std::string stronline;
        dis(stronline, nidk2);
        std::string straw;
        std::string strah;
        //std::string strap = strax + "," + stray + "," + snum + "," + straw + "," + strah;
        std::string strap = strax + "," + stray + "," + straindex + "," + stronline;
		strcpy(msg1, strap.c_str());
		send(Connection, msg1, sizeof(msg1), 0);
	    msg1[256];
	    
	    //if (pnum >= 0) {online[pnum] = 1;}
	    
		//Sleep(10);
		//std::cout << p.x << p.y << std::endl;
        window.setView(view);
        window.clear();
        
        #include "drawmap.h"
        
        window.draw(herosprite);
        window.draw(herosprites[0]);
        window.draw(herosprites[1]);
        window.draw(herosprites[2]);
        window.display();
        
    }

	return 0;
}
