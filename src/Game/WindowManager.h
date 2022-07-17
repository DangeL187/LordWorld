class WindowManager {
protected:
    std::shared_ptr<RenderWindow> window;
    unsigned int window_w = 1920;
    unsigned int window_h = 1080;
    View view;
public:
    void createWindow() {
        window = std::make_shared<RenderWindow>(VideoMode(window_w, window_h), "Lord World");
    }
    float viewGetCenterX() {
        return view.getCenter().x;
    }
    float viewGetCenterY() {
        return view.getCenter().y;
    }
    void viewReset() {
        view.reset(FloatRect(0, 0, window_w, window_h));
    }
    void windowHandleEvents() {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
        }
    }
    void windowSetView() {
        window->setView(view);
    }
    void windowClear() {
        window->clear();
    }
    void windowDisplay() {
        window->display();
    }
    bool windowIsOpen() {
        return window->isOpen();
    }
};
