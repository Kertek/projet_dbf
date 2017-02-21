<?php

/* /default/formulaire.html.twig */
class __TwigTemplate_2aee2fde581b6131b6b12e6f140fbb9e9841e5ffdd676e211fb86f1f3b206fda extends Twig_Template
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
        $__internal_76c05d395f425d3c4540f03cff19e97ff38e55266afb8d1c4717cd667b560f5d = $this->env->getExtension("native_profiler");
        $__internal_76c05d395f425d3c4540f03cff19e97ff38e55266afb8d1c4717cd667b560f5d->enter($__internal_76c05d395f425d3c4540f03cff19e97ff38e55266afb8d1c4717cd667b560f5d_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/formulaire.html.twig"));

        // line 1
        echo "<!DOCTYPE html>
<html>
<head>
\t<title>Formulaire</title>
</head>
<body>
<form method=\"post\", action='/cible.php'>
\tPrenom:<br>
\t<input type=\"text\", name=\"Firstname\">
\t<br>
\tNom:<br>
\t<input type=\"text\", name=\"Lastname\">
\t<br>
\tCommentaire:<br>
\t<textarea name=\"Comments\", rows=\"8\", cols=\"45\">
\tMet tes commentaires
\t</textarea>
\t<br>
\t<button type=\"submit\">Envoyer/Send</button>
</form>

</body>

</html>";
        
        $__internal_76c05d395f425d3c4540f03cff19e97ff38e55266afb8d1c4717cd667b560f5d->leave($__internal_76c05d395f425d3c4540f03cff19e97ff38e55266afb8d1c4717cd667b560f5d_prof);

    }

    public function getTemplateName()
    {
        return "/default/formulaire.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  22 => 1,);
    }
}
/* <!DOCTYPE html>*/
/* <html>*/
/* <head>*/
/* 	<title>Formulaire</title>*/
/* </head>*/
/* <body>*/
/* <form method="post", action='/cible.php'>*/
/* 	Prenom:<br>*/
/* 	<input type="text", name="Firstname">*/
/* 	<br>*/
/* 	Nom:<br>*/
/* 	<input type="text", name="Lastname">*/
/* 	<br>*/
/* 	Commentaire:<br>*/
/* 	<textarea name="Comments", rows="8", cols="45">*/
/* 	Met tes commentaires*/
/* 	</textarea>*/
/* 	<br>*/
/* 	<button type="submit">Envoyer/Send</button>*/
/* </form>*/
/* */
/* </body>*/
/* */
/* </html>*/
