#ifndef VIEW_H_
#define VIEW_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include <memory>
#include <iostream> //TODO remove this
#include "Interface/Interface.h"
#include "Interface/CLI/Token.h"
#include "Utils/panel.h"

namespace Interface
{
    //This class wraps View, so a shared_ptr<BaseView> can be used
    class BaseView
    {
    public:
        virtual void refreshView()=0;
        virtual void redrawView()=0;
        virtual ~BaseView(){}
        virtual WINDOW* getTitleWin()=0;
        virtual WINDOW* getNameWin()=0;
        virtual WINDOW* getDataWin()=0;

        //expands tokens that are dependent on context. i.e., passing '1' in place of a
        //location name when viewing adjacent locations.
        virtual bool expandArg(CLI::Token&)=0;

        BaseView(){} //This should only be used by shared_ptr
        BaseView(const BaseView&) = delete;
        BaseView& operator=(const BaseView&) = delete;

    };
    typedef std::shared_ptr<BaseView> View_ptr;


    template<typename T>
    class View : public BaseView
    {
    public:
        virtual void refreshView()=0;
        void redrawView();
        WINDOW* getTitleWin() override {return titleWin;}
        WINDOW* getNameWin() override {return nameWin;}
        WINDOW* getDataWin() override {return dataWin;}
        virtual bool expandArg(CLI::Token&) override {return false;}

        virtual ~View()
        {
            /*
            * FIXME delwin(viewWin); should be called here but
            * this crashes when exiting. viewWin has a non
            * null value at this point, so this is possibly
            * a bug with pdcurses. For now we leak memory.
            */
        }

        const T viewSubject;
    protected:
        View(T _viewSubject, std::string _viewType);
        View(const View&) = delete;
        View& operator=(const View&) = delete;

        std::string viewType;
        WINDOW* titleWin;
        WINDOW* nameWin;
        WINDOW* dataWin;
    };


    template<typename T>
    View<T>::View(T _viewSubject, std::string _viewType) :
        viewSubject(_viewSubject),
        viewType(_viewType)

    {
        this->titleWin = subwin(mainwin, LINES-3, COLS, 3, 0);
        this->nameWin = subwin(titleWin, LINES-5, (COLS-2)/2, 4, 1);
        this->dataWin = subwin(titleWin, LINES-5, (COLS-2)/2, 4, COLS/2);
        this->redrawView();
    }

    template<typename T>
    void View<T>::redrawView()
    {
        wclear(titleWin);
        box(this->titleWin, 0, 0);
        std::string status = CLI::contextAsString(currentContext) + "(" + viewSubject->getName() + "):" + viewType;
        mvwprintw(this->titleWin, 0, 2, status.c_str());

        wrefresh(this->titleWin);
    }



}
#endif
