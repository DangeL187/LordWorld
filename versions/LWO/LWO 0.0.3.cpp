#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string.h>
#include "Files/map.h"
#include "Files/view.h"
#include "Files/split.h"

using namespace sf;

Sprite herosprite;
Sprite herosprites[3];
String File[3]{"Images/main.png", "Images/main2.png", "Images/main3.png"};
Image all_images[3]; Texture all_textures[3];
Image off_image; Texture off_texture;

int online[100];
int nidk1 = -1; //ur own index
int nidk2 = -1; //ur own online
std::string users[100]; //0, 1, 2...
int user;
std::string login; std::string password;
std::string smsg2;
char msg1[256]; //msg with login and password
char msg2[256]; //msg with error

#include "Files/classes.h"

void ClientHandler(int connect) {
	while (true) {
		char msg[256] = "\0"; //msg from server
        auto what = recv(connect, msg, sizeof(msg), 0); //receive
        if (what != 0) {
            std::cout << msg << std::endl;
        } else {
            std::cout << "Error: the server was shutted down\n";
            exit(1);
        }

		std::string idk = msg;
	    std::vector<std::string> idk0 = split(idk, ',');
		int tidk1 = std::stoi(idk0[0]); float idk1 = tidk1; //x
	    int tidk2 = std::stoi(idk0[1]); float idk2 = tidk2; //y
	    int idk3 = std::stoi(idk0[2]); //index
	    int idk4 = std::stoi(idk0[3]); //online

	    if (nidk1 == idk3) {
	    	std::cout << "ERROR\n"; idk3 = -2; exit(2);
	    }

		if (online[idk3] != idk4 && idk4 == 1) { //if online
		    std::cout << "loading models\n";
			herosprites[idk3].setTexture(all_textures[idk3]);
			herosprites[idk3].setTextureRect(IntRect(0, 0, 25.0, 31.0));
		}
		else if (online[idk3] != idk4 && idk4 == 0) { //if offline
			herosprites[idk3].setTexture(off_texture);
			herosprites[idk3].setTextureRect(IntRect(0, 0, 25.0, 31.0));
		}

		online[idk3] = idk4;

		if (online[idk3] == 1) {
			herosprites[idk3].setPosition(idk1, idk2);
		}
    }
}

bool checklp(int connect) { //check logpass
	recv(connect, msg2, sizeof(msg2), 0); //recv error msg
	smsg2 = msg2;
	if (smsg2 == "Wrong login or password\nMaybe you are not registered?") {
		std::cout << smsg2 << std::endl;
		return true;
	}
	else if (smsg2 == "This account is already online") {
		std::cout << smsg2 << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void login_form(int connect) {
    std::cout << "Enter your login: "; std::cin >> login;
    std::cout << "Enter your password: "; std::cin >> password; std::cout << std::endl;
	std::string logpass = login + "," + password; strcpy(msg1, logpass.c_str());
    send(connect, msg1, sizeof(msg1), 0); //send login and password to server
    if (!checklp(connect)) { //if correct
        std::cout << smsg2 << std::endl;
    }
}

int main() {
    #include "Files/client.h"
    #include "Files/images.h"

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player p(500, 500, 25.0, 31.0);

	Other o(500, 500, 25.0, 31.0, 0);
    Other o1(900, 500, 25.0, 31.0, 1);
    Other o2(400, 500, 25.0, 31.0, 2);

    Image map_image;
	map_image.loadFromFile("Images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

    float heroteleporttimer = 0;
    float CurrentFrame = 0;
	Clock clock;

    while (window.isOpen()) {

	    float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        heroteleporttimer += time;

        if (heroteleporttimer > 3000) {
		    //herosprite.setPosition(0, 120); heroteleporttimer = 0;
		}

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        #include "Files/keys.h"

        p.update(time);

        std::string strax = std::to_string(p.x);
        std::string stray = std::to_string(p.y);
        std::string straindex = std::to_string(nidk1);
        std::string stronline = std::to_string(nidk2);
        std::string straw;
        std::string strah;
        std::string strap = strax + "," + stray + "," + straindex + "," + stronline;
		strcpy(msg1, strap.c_str());
		send(Connection, msg1, sizeof(msg1), 0);
	    msg1[256];

        window.setView(view);
        window.clear();

        #include "Files/drawmap.h"

        window.draw(herosprite);
        for (int lol = 0; lol <= 2; lol++) {
        	if (lol != nidk1) {
			    window.draw(herosprites[lol]);
        	}
        }
        window.draw(herosprites[0]);
        window.draw(herosprites[1]);
        window.draw(herosprites[2]);
        window.display();

    }

	return 0;
}
