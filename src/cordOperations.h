bool isCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
}

float getDistanceBetween(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return pow((dx*dx + dy*dy), 0.5);
}

bool isInsideRectangle(float obj_x, float obj_y, float rect_x, float rect_y, float rect_w, float rect_h) {
    return (rect_x <= obj_x &&
            obj_x <= rect_x + rect_w &&
            rect_y <= obj_y &&
            obj_y <= rect_y + rect_h);
}

bool isInsideRectangle(sf::Vector2f obj_pos, float rect_x, float rect_y, float rect_w, float rect_h) {
    return (rect_x <= obj_pos.x &&
            obj_pos.x <= rect_x + rect_w &&
            rect_y <= obj_pos.y &&
            obj_pos.y <= rect_y + rect_h);
}

bool isInsideRectangle(float obj_x, float obj_y, sf::Vector2f rect_pos, float rect_w, float rect_h) {
    return (rect_pos.x <= obj_x &&
            obj_x <= rect_pos.x + rect_w &&
            rect_pos.y <= obj_y &&
            obj_y <= rect_pos.y + rect_h);
}

bool isInsideRectangle(sf::Vector2f obj_pos, sf::Vector2f rect_pos, float rect_w, float rect_h) {
    return (rect_pos.x <= obj_pos.x &&
            obj_pos.x <= rect_pos.x + rect_w &&
            rect_pos.y <= obj_pos.y &&
            obj_pos.y <= rect_pos.y + rect_h);
}
