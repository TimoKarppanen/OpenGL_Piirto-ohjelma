#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

/* Funktioiden prototyypitykset */

int Initialize_Window();
void StartProgram();
void Draw_Triangle();
void Draw_Rectangle();
void Draw_Hexagon();
void Draw_Parallellogram();

GLFWwindow* window; // window-olio m‰‰ritet‰‰n globaaliksi.

int main()
{
    setlocale(LC_ALL, "fi-FI"); // Asetetaan ohjelma tunnistamaan suomenkieliset kirjaimet
    StartProgram();
    return 0;
}

void StartProgram() {

    int choice = 0;

    do {

        cout << "                   " << endl;
        cout << " Tervetuloa OPENGL piirto-ohjelmaan " << endl;
        cout << "                   " << endl;
        cout << " Valitse toiminto " << endl;
        cout << "                   " << endl;
        cout << "(1) Piirr‰ Kolmio " << endl;
        cout << "(2) Piirr‰ Neliˆ " << endl;
        cout << "(3) Piirr‰ Kuusikulmio " << endl;
        cout << "(4) Piirr‰ Suunnikas" << endl;

        cin >> choice;

        switch (choice) {

        case 1: {
            Draw_Triangle();
            break;
        }
        case 2: {
            Draw_Rectangle();
            break;
        }
        
        case 3: {
            Draw_Hexagon();
            break;
        }
        case 4: {
            Draw_Parallellogram();
            break;
        }
      }
    }
    while (choice != 0);
}

int Initialize_Window() {

    /* GLFW-kirjaston alustus */

    if (!glfwInit())
        return -1;

    /* Alustetaan window olioon ikkunanluonti funktio, ja m‰‰ritet‰‰n ikkunan suuruus, sek‰ nimi */

    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);

    /* Tarkistetaan ikkunan tila ... */

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Asetetaan window-olion konteksti t‰m‰n hetkiseksi */

    glfwMakeContextCurrent(window);

    /* GLEW-kirjaston alustus */
 
    if (glewInit() != GLEW_OK) {
        cout << " error " << endl;
    }

    /* Tulostetaan OpenGL:n versio */

    cout << "                    " << endl;
    cout << " K‰ytˆss‰ on OpenGL versio : " << glGetString(GL_VERSION) << endl;
    cout << "                    " << endl;
    return 0;
}

void Draw_Triangle() {

    /* Alustetaan window-olio*/

    Initialize_Window();

    /* Asetetaan koordinaatit piirrett‰v‰lle kuviolle */

    float positions[6] = {
      -0.5f, -0.5f, /* x ja y */
      0.5f, -0.5f,
      0.0f, 0.5f,
    };

    unsigned int buffer;

    /* Luodaan 1 buffer-olio */

    glGenBuffers(1, &buffer);

    /* Valitaan luotu buffer-olio */

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    /* Asetetaan bufferin sis‰lle dataa */

    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // M‰‰ritet‰‰n avattavan ikkunan sijainti
    
    glfwSetWindowPos(window, 400, 200);
    
    /* Looppaa niin pitk‰‰n kunnes k‰ytt‰j‰ sulkee ikkunan */

    while (!glfwWindowShouldClose(window))
    {
        /* Renderˆid‰‰n */
        /* Vaihtaa ikkunan taustav‰rin */
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* M‰‰ritet‰‰n mink‰ tyyppisi‰ kuvioita halutaan piirt‰‰ ja kulmien m‰‰r‰ */

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Vaihdetaan etu ja taka bufferrien paikat */
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    /* Terminoidaan ikkuna */

    glfwTerminate();
   
}  

void Draw_Rectangle() {

    Initialize_Window();

    float positions[15] = { 
            0.5f, 0.5f,  
            0.5f,-0.5f,  
           -0.5f,-0.5f,   
           -0.5f, 0.5f
    };

    unsigned int buffer;

    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(float), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glfwSetWindowPos(window, 400, 200);

    while (!glfwWindowShouldClose(window))
    {
       
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glVertexPointer(4, GL_FLOAT, 1, window);
        glDrawArrays(GL_QUADS, 0, 4);
      
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
    glfwTerminate();
}

void Draw_Hexagon() {

    Initialize_Window();

    float positions[12] = {
    
       -0.25f, 0.5f,
       0.25f, 0.5f,
       0.5f, 0.0f,
       0.25f, -0.5f,
       -0.25f, -0.5f,
       -0.5f, 0.0f,
     
    };

    unsigned int buffer;

    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glfwSetWindowPos(window, 400, 200);

    while (!glfwWindowShouldClose(window))
    {
     
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glVertexPointer(4, GL_FLOAT, 1, positions);
        glDrawArrays(GL_POLYGON, 0, 6);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}


void Draw_Parallellogram() {

    Initialize_Window();

    float positions[15] = {
      -0.5f, -0.5f,
        -0.25f, 0.25f,
        0.45f, 0.25f,
        0.25f, -0.5f,
    };

    unsigned int buffer;

    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glfwSetWindowPos(window, 400, 200);

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glVertexPointer(4, GL_FLOAT, 0, positions);
        glDrawArrays(GL_QUADS, 0, 4);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

}

