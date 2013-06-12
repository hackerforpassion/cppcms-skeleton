/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@> 
 * @package  Forms
 *
 */

#ifndef @MAIN_CLASS_HEADER@_%%FORM_INCLUDE%%
#define @MAIN_CLASS_HEADER@_%%FORM_INCLUDE%%


#include <cppcms/form.h>

namespace forms{
namespace %%CONTROLLER_NS%% {

/**
 * @struct %%FORM_NAME%%
 * @brief  %%FORM_DESCRIPTION%%
 * @since  %%FORM_TODAY%%
 *
 */
struct %%FORM_STRUCT%% : public cppcms::form {

    //%%%NEXT_WIDGET_VAR_MARKER%%%

    /**
     * @brief button to submit the form
     */
    cppcms::widgets::submit submit;

    /**
     * @brief Constructor
     */
    %%FORM_STRUCT%%() {

        //%%%NEXT_WIDGET_ADD_MARKER%%%

        add(submit);
        submit.name(
            cppcms::locale::translate("%%FORM_SUBMIT_UI%%")
        );
        submit.value("submit");
    }


};


} // end of namespace %%CONTROLLER_NS%%
}// end of namespace forms


#endif


