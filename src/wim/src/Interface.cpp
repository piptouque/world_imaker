//
// Created by piptouque on 25/12/2019.
//

#include "../include/wim/Interface.hpp"


namespace wim {

    bool Interface::run() const
    {
        bool loop = true;
        this->processState();
        loop = this->processEvents();
        return loop;
    }

    void Interface::processState() const
    {


    }

    void Interface::processKeyboardUp(const SDL_Event& e) const
    {
        SizeInt width, length;
        switch(e.key.keysym.sym)
        {
            case SDLK_p:
                //Adding new pointlight
                this->addPointLight(PointLight::Random());
                break;
            case SDLK_m:
                //adding new directional light
                this->addDirectionLight(DirectionLight::Random());
                break;

            case SDLK_o:
                //ambiant lighting off
                this->setAmbiantLight(AmbiantLight(Colour(0,0,0)));
                break;
            case SDLK_i:
                // ambiant lighting on
                this->setAmbiantLight(AmbiantLight::Random());
                break;
            case SDLK_n:
                //changing World
                width =_model->world()->getWidth();
                length = _model->world()->getLength();
                *_model->world() = CubeWorld::Random(width, length);
            default:
                break;
        }
    }

    void Interface::processMouseMotion(const SDL_Event& e) const
    {
        //rotation
        if( this->isRotating() )
        {
            GLfloat leftMotion, upMotion;
            upMotion = -e.motion.yrel;
            leftMotion = e.motion.xrel;
            this->rotate(upMotion, leftMotion);
        }
    }


    void Interface::processMouseWheel(const SDL_Event& e) const
    {
        int zoomDir = e.wheel.y;
        if( zoomDir )
        {
            this->zoom(zoomDir);
        }
    }

    bool Interface::processEvents() const {

        bool loop = true;

        SDL_Event e;
        while (this->pollEvent(e)) {
            //ImGui does its thing
           // ImGui_ImplSDL2_ProcessEvent(&e);

            switch (e.type) {
                case SDL_QUIT :
                    loop = false;
                    break;

                case SDL_KEYUP  :
                    //Function in Controller or switch and case ?
                    this->processKeyboardUp(e);
                    break;

                case SDL_MOUSEMOTION :
                    //Get the position
                    this->processMouseMotion(e);
                    break;

                case SDL_MOUSEWHEEL:
                    this->processMouseWheel(e);
                    break;

                case SDL_MOUSEBUTTONDOWN :
                    //
                    break;

                default :
                    break;
            }
        }
        return loop;
    }


    void Interface::getRelativePosMouse(GLfloat& xRel, GLfloat& yRel) const
    {
        int windowWidth, windowHeight;
        this->windowManager()->getWindowSize(windowWidth, windowHeight);
        glm::ivec2 mousePos = this->windowManager()->getMousePosition();
        xRel = (mousePos.x - windowWidth/2)/(GLfloat)windowWidth;
        yRel = (mousePos.y - windowHeight/2)/(GLfloat)windowHeight;
    }

    void Interface::zoom(const GLint zoomDir) const
    {
        _displayer->getCameraManagerPtr()->zoom(zoomDir);
    }

    void Interface::rotate(const GLfloat phi, const GLfloat theta) const
    {
        _displayer->getCameraManagerPtr()->rotate(phi, theta);
    }

    void Interface::addPointLight(const PointLight &light) const
    {
        try
        {
            _model->addPointLight(light);
        }
        catch( Exception& e )
        {
            std::cout << e.what() << std::endl;
        }
    }
    void Interface::addDirectionLight(const DirectionLight &light) const
    {
        try
        {
            _model->addDirectionLight(light);
        }
        catch( Exception& e )
        {
            std::cout << e.what() << std::endl;
        }
    }

    void Interface::setAmbiantLight(const AmbiantLight &light) const
    {
        _model->lightManager()->setAmbiant(light);
    }
}