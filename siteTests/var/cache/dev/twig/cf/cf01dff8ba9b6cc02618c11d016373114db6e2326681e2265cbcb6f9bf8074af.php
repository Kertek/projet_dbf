<?php

/* base.html.twig */
class __TwigTemplate_856a73327aa88aeacb8afdabac15f427cf1c4b0a29c343496fa2afa281b6e53f extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'stylesheets' => array($this, 'block_stylesheets'),
            'body' => array($this, 'block_body'),
            'javascripts' => array($this, 'block_javascripts'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_1b8532699695b8b2b2504175c8cd5f1efbce7728efd50ccc5a3863802a3f889f = $this->env->getExtension("native_profiler");
        $__internal_1b8532699695b8b2b2504175c8cd5f1efbce7728efd50ccc5a3863802a3f889f->enter($__internal_1b8532699695b8b2b2504175c8cd5f1efbce7728efd50ccc5a3863802a3f889f_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "base.html.twig"));

        // line 1
        echo "<!DOCTYPE html>
<html>
    <head>
        <meta charset=\"UTF-8\" />
        <title>";
        // line 5
        $this->displayBlock('title', $context, $blocks);
        echo "</title>
        ";
        // line 6
        $this->displayBlock('stylesheets', $context, $blocks);
        // line 7
        echo "        <link rel=\"icon\" type=\"image/x-icon\" href=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('asset')->getAssetUrl("favicon.ico"), "html", null, true);
        echo "\" />
    </head>
    <body>
        ";
        // line 10
        $this->displayBlock('body', $context, $blocks);
        // line 11
        echo "        ";
        $this->displayBlock('javascripts', $context, $blocks);
        // line 12
        echo "    </body>
</html>
";
        
        $__internal_1b8532699695b8b2b2504175c8cd5f1efbce7728efd50ccc5a3863802a3f889f->leave($__internal_1b8532699695b8b2b2504175c8cd5f1efbce7728efd50ccc5a3863802a3f889f_prof);

    }

    // line 5
    public function block_title($context, array $blocks = array())
    {
        $__internal_e04703cf51b5743c6b5065e40543b7ed5335a6dd74c62f412bf7f78d866d04cc = $this->env->getExtension("native_profiler");
        $__internal_e04703cf51b5743c6b5065e40543b7ed5335a6dd74c62f412bf7f78d866d04cc->enter($__internal_e04703cf51b5743c6b5065e40543b7ed5335a6dd74c62f412bf7f78d866d04cc_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo "Welcome!";
        
        $__internal_e04703cf51b5743c6b5065e40543b7ed5335a6dd74c62f412bf7f78d866d04cc->leave($__internal_e04703cf51b5743c6b5065e40543b7ed5335a6dd74c62f412bf7f78d866d04cc_prof);

    }

    // line 6
    public function block_stylesheets($context, array $blocks = array())
    {
        $__internal_6bc323db693454fd2bd1e8f9af8b523190c14003dd0388a7a0f493a299edb50c = $this->env->getExtension("native_profiler");
        $__internal_6bc323db693454fd2bd1e8f9af8b523190c14003dd0388a7a0f493a299edb50c->enter($__internal_6bc323db693454fd2bd1e8f9af8b523190c14003dd0388a7a0f493a299edb50c_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "stylesheets"));

        
        $__internal_6bc323db693454fd2bd1e8f9af8b523190c14003dd0388a7a0f493a299edb50c->leave($__internal_6bc323db693454fd2bd1e8f9af8b523190c14003dd0388a7a0f493a299edb50c_prof);

    }

    // line 10
    public function block_body($context, array $blocks = array())
    {
        $__internal_6827bdba5a62651762b7d3b04f2a2fddabac373a6f8c29b2a0fb7ab021d92fa0 = $this->env->getExtension("native_profiler");
        $__internal_6827bdba5a62651762b7d3b04f2a2fddabac373a6f8c29b2a0fb7ab021d92fa0->enter($__internal_6827bdba5a62651762b7d3b04f2a2fddabac373a6f8c29b2a0fb7ab021d92fa0_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        
        $__internal_6827bdba5a62651762b7d3b04f2a2fddabac373a6f8c29b2a0fb7ab021d92fa0->leave($__internal_6827bdba5a62651762b7d3b04f2a2fddabac373a6f8c29b2a0fb7ab021d92fa0_prof);

    }

    // line 11
    public function block_javascripts($context, array $blocks = array())
    {
        $__internal_719d14ddae2f0f7eefb0c333211fa29bce791196ce90b8dea0d67edfb6de26c3 = $this->env->getExtension("native_profiler");
        $__internal_719d14ddae2f0f7eefb0c333211fa29bce791196ce90b8dea0d67edfb6de26c3->enter($__internal_719d14ddae2f0f7eefb0c333211fa29bce791196ce90b8dea0d67edfb6de26c3_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "javascripts"));

        
        $__internal_719d14ddae2f0f7eefb0c333211fa29bce791196ce90b8dea0d67edfb6de26c3->leave($__internal_719d14ddae2f0f7eefb0c333211fa29bce791196ce90b8dea0d67edfb6de26c3_prof);

    }

    public function getTemplateName()
    {
        return "base.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  93 => 11,  82 => 10,  71 => 6,  59 => 5,  50 => 12,  47 => 11,  45 => 10,  38 => 7,  36 => 6,  32 => 5,  26 => 1,);
    }
}
/* <!DOCTYPE html>*/
/* <html>*/
/*     <head>*/
/*         <meta charset="UTF-8" />*/
/*         <title>{% block title %}Welcome!{% endblock %}</title>*/
/*         {% block stylesheets %}{% endblock %}*/
/*         <link rel="icon" type="image/x-icon" href="{{ asset('favicon.ico') }}" />*/
/*     </head>*/
/*     <body>*/
/*         {% block body %}{% endblock %}*/
/*         {% block javascripts %}{% endblock %}*/
/*     </body>*/
/* </html>*/
/* */
