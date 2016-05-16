#include <iostream>
#include <cmath>

using namespace std;

struct point {
    long double x;
    long double y;
    long double m;
};

bool in_ellipse(point p) {
    return !(p.x > -.01 && p.x < .01 && p.y > 0);
}

double d(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

long double slope(long double m_o, long double m_b) {
    return  (2*m_b + m_o*m_b*m_b - m_o) / (2*m_o*m_b - m_b*m_b +1);
}

long double p_quad(long double a, long double b, long double c) {
    return (-b+sqrt(b*b - 4*a*c))/(2*a);
}

long double n_quad(long double a, long double b, long double c) {
    return (-b-sqrt(b*b-4*a*c))/(2*a);
}

point next(point p) {
    long double m_r = slope(p.m, -4*p.x/p.y);
    long double c = p.y - p.x*m_r;
    
    long double x_1 = p_quad(4+m_r*m_r, 2*m_r*c, c*c-100);
    long double x_2 = n_quad(4+m_r*m_r, 2*m_r*c, c*c-100);
    long double y_1 = x_1*m_r + c;
    long double y_2 = x_2*m_r + c;

    point p_1;
    p_1.x = x_1;
    p_1.y = y_1;
    p_1.m = m_r;

    point p_2;
    p_2.x = x_2;
    p_2.y = y_2;
    p_2.m = m_r;

    return d(p_1, p) < d(p_2, p) ? p_2 : p_1;
}


int main() {
    point p;
    p.x = 1.4L;
    p.y = -9.6L;
    p.m = (10.1L + 9.6L)/-1.4L;
    int n;

    for(n = 1; in_ellipse(p); n++ ) {
        cout << n << "\n";
        cout << "("  << p.x << "," << p.y << ")\n\n";
        p = next(p);
    }
}
