/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@> 
 * @package  Main
 *
 */

#include <iostream>

#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppdb/frontend.h>
#include <cppcms/json.h>

#include "@MAIN_CLASS@.h"

#include "cppcms_skel/generics/Config.h"

using namespace std;
using namespace cppcms;

int main(int argc,char ** argv)
{
    //TODO send notice message to logs instead of cout

    service app(argc, argv);
    /*load some conf defined variables*/
    Config *conf = Config::get_instance();

    conf->sqlite3Path = app.settings().get<string>(
        "@PROJECT_NAME_CODE@.sqlite3.path"
    );

    Config::set_css_path(
        app.settings().get<string>(
            "skel.cssPath"
        )
    );

    Config::set_img_path(
        app.settings().get<string>(
            "skel.imgPath"
        )
    );
    
    Config::set_js_path(
        app.settings().get<string>(
            "skel.jsPath"
        )
    );





    Config::set_inner_css_folder(
        app.settings().get<string>(
            "skel.innerCssFolder"
        )
    );

    Config::set_inner_img_folder(
        app.settings().get<string>(
            "skel.innerImgFolder"
        )
    );
    
    Config::set_inner_js_folder(
        app.settings().get<string>(
            "skel.innerJsFolder"
        )
    );





        
    /*start the graph database*/

    //singletons::ActionId::get_instance();
    /*instantiate the website application*/
    cout << "[NOTICE] website to be launched" << endl;

    //booster::intrusive_ptr<apps::Tatoeba> tatoApp = new apps::Tatoeba(app);

    app.applications_pool().mount(
        cppcms::applications_factory<apps::@MAIN_CLASS@>()
    );
    /*launch it */
    cout << "[NOTICE] website launched" << endl;
    app.run();
    cout << "[NOTICE] website stopped" << endl;

    /*time to destroy all the singletons*/
    //SearchEngine::kill();
    Config::kill();
}

