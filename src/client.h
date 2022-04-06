	int Connection;
	struct sockaddr_in addr;
	Connection = socket(AF_INET, SOCK_STREAM, 0);
	if (Connection < 0) {
	    perror("socket");
	    exit(1);
	}

    addr.sin_family = AF_INET;
    addr.sin_port = htons(1337);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(Connection, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(2);
    } std::cout << "Connected!\n";

    login_form(Connection); //login

	char msg[256];
	recv(Connection, msg, sizeof(msg), 0);
	//std::cout << "MSG: " << msg << std::endl;
	std::string idk2 = msg;
	std::vector<std::string> idk01 = split(idk2, ',');
	nidk1 = std::stoi(idk01[1]); //ur own index
    nidk2 = std::stoi(idk01[0]); //ur own online
	online[nidk1] = nidk2;

	if (user == -1) {
		std::cout << "Error: invalid login number!\n";
		return 1;
	}

	pthread_t thread1;
    int result = pthread_create(&thread1, NULL, reinterpret_cast<void *(*)(void *)>(ClientHandler),
                                reinterpret_cast<void *>(Connection));
    if (result != 0) {
        exit(3);
    }

	char msg1[256];
