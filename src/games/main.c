#include <X11/Xlib.h>
#include <unistd.h>

int main() {
    Display *display;
    Window window;
    XEvent event;
    int screen;

    // Abrir conexión con el servidor X
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        return -1;
    }

    screen = DefaultScreen(display);

    // Crear una ventana
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 400, 400, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    // Seleccionar los eventos que queremos escuchar
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Mostrar la ventana
    XMapWindow(display, window);

    // Bucle de eventos
    while (1) {
        XNextEvent(display, &event);

        // Dibujar cuando la ventana se expone
        if (event.type == Expose) {
            GC gc = XCreateGC(display, window, 0, NULL);
            XSetForeground(display, gc, BlackPixel(display, screen));
            // Dibujar un punto en (50, 50)
	    for(int i = 0; i < 32; i++)
		XDrawPoint(display, window, gc, 50 + i, 50);
            XFreeGC(display, gc);
        }

        // Salir cuando se presiona una tecla
        if (event.type == KeyPress) {
            break;
        }
    }

    // Cerrar la conexión con el servidor X
    XCloseDisplay(display);
    return 0;
}
