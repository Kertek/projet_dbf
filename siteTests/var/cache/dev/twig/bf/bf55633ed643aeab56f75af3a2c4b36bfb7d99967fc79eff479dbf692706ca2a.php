<?php

/* /default/cible.html.twig */
class __TwigTemplate_1ed49e2f92062c8569e5b6b418dc8c679c4d9c1fb12e613014766f00327b2357 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_278d4e281c89d1c5cdd84370935a0e5719d88fd606d9ca2c450bbb724a067339 = $this->env->getExtension("native_profiler");
        $__internal_278d4e281c89d1c5cdd84370935a0e5719d88fd606d9ca2c450bbb724a067339->enter($__internal_278d4e281c89d1c5cdd84370935a0e5719d88fd606d9ca2c450bbb724a067339_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/cible.html.twig"));

        // line 1
        echo "<!DOCTYPE html>
<html>
<head>
\t<title>Cible</title>
</head>
<body>
\t<p>Bonjour: <?php
\t\techo \$_POST[\"Firstname\"];
\t?></p>
</body>
</html>";
        
        $__internal_278d4e281c89d1c5cdd84370935a0e5719d88fd606d9ca2c450bbb724a067339->leave($__internal_278d4e281c89d1c5cdd84370935a0e5719d88fd606d9ca2c450bbb724a067339_prof);

    }

    public function getTemplateName()
    {
        return "/default/cible.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  22 => 1,);
    }
}
/* <!DOCTYPE html>*/
/* <html>*/
/* <head>*/
/* 	<title>Cible</title>*/
/* </head>*/
/* <body>*/
/* 	<p>Bonjour: <?php*/
/* 		echo $_POST["Firstname"];*/
/* 	?></p>*/
/* </body>*/
/* </html>*/
