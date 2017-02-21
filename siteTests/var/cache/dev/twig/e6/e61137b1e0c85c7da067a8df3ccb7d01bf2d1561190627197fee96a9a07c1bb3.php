<?php

/* myblog.base.html.twig */
class __TwigTemplate_4f08b693011d035cfcda0e671821034afd23b2c4233204e1bb6a96872bab0c00 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'body' => array($this, 'block_body'),
            'javascript' => array($this, 'block_javascript'),
            'stylesheets' => array($this, 'block_stylesheets'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_2a00448b14b75924fdf2bee135d5b00ebb5ad1632b82cd349b009d6be1f54586 = $this->env->getExtension("native_profiler");
        $__internal_2a00448b14b75924fdf2bee135d5b00ebb5ad1632b82cd349b009d6be1f54586->enter($__internal_2a00448b14b75924fdf2bee135d5b00ebb5ad1632b82cd349b009d6be1f54586_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "myblog.base.html.twig"));

        // line 1
        echo "<!DOCTYPE>
<html lang=\"en\">
    <head>
        <meta charset=\"UTF-8\" />
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>
        <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">
 \t\t<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js\"></script>
  \t\t<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script>
        <title>";
        // line 9
        $this->displayBlock('title', $context, $blocks);
        echo "</title>
    </head>
    <body>
    <nav class=\"navbar navbar-default navbar-fixed-top\" role=\"navigation\">
  \t\t<div class=\"container-fluid\">
\t\t\t<ul class=\"nav navbar-nav\">
                  <li><a href=\"/presentation\">Acous<br><u class=\"fin-header\">acous.secure@gmail.com</u></a></li>
\t\t\t</ul>
    \t\t<!-- Collect the nav links, forms, and other content for toggling -->
    \t\t<div class=\"sd-nav\" id=\"bs-example-navbar-collapse-1\">
\t\t\t\t <ul class=\"nav navbar-nav list\">
                      <li><a href=\"/\">Home</a></li>
                      <li><a href=\"/articles\">Articles</a></li>
                      <li><a href=\"/\">Games</a></li>
    \t\t\t</ul>
   \t\t\t</div><!-- /.navbar-collapse -->
  \t\t</div><!-- /.container-fluid -->
\t</nav>
\t<div class=\"entry-text-cont\">
    ";
        // line 28
        $this->displayBlock('body', $context, $blocks);
        // line 29
        echo "    </div>
    ";
        // line 30
        $this->displayBlock('javascript', $context, $blocks);
        // line 31
        echo "    ";
        $this->displayBlock('stylesheets', $context, $blocks);
        // line 35
        echo "    </body>








</html>";
        
        $__internal_2a00448b14b75924fdf2bee135d5b00ebb5ad1632b82cd349b009d6be1f54586->leave($__internal_2a00448b14b75924fdf2bee135d5b00ebb5ad1632b82cd349b009d6be1f54586_prof);

    }

    // line 9
    public function block_title($context, array $blocks = array())
    {
        $__internal_fce553f847514c8b2936e28a7bf879bd0f4b1288f9986b309368df8f6f4fb98e = $this->env->getExtension("native_profiler");
        $__internal_fce553f847514c8b2936e28a7bf879bd0f4b1288f9986b309368df8f6f4fb98e->enter($__internal_fce553f847514c8b2936e28a7bf879bd0f4b1288f9986b309368df8f6f4fb98e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        
        $__internal_fce553f847514c8b2936e28a7bf879bd0f4b1288f9986b309368df8f6f4fb98e->leave($__internal_fce553f847514c8b2936e28a7bf879bd0f4b1288f9986b309368df8f6f4fb98e_prof);

    }

    // line 28
    public function block_body($context, array $blocks = array())
    {
        $__internal_c4b36623a938de9e735d3f23f4d5b8caafbf6967c1364fc936a04465e8c629f7 = $this->env->getExtension("native_profiler");
        $__internal_c4b36623a938de9e735d3f23f4d5b8caafbf6967c1364fc936a04465e8c629f7->enter($__internal_c4b36623a938de9e735d3f23f4d5b8caafbf6967c1364fc936a04465e8c629f7_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        
        $__internal_c4b36623a938de9e735d3f23f4d5b8caafbf6967c1364fc936a04465e8c629f7->leave($__internal_c4b36623a938de9e735d3f23f4d5b8caafbf6967c1364fc936a04465e8c629f7_prof);

    }

    // line 30
    public function block_javascript($context, array $blocks = array())
    {
        $__internal_10b1902867edbffcef220b0971c0dd78eb414f6020d37986e25a5cf2ebb6da68 = $this->env->getExtension("native_profiler");
        $__internal_10b1902867edbffcef220b0971c0dd78eb414f6020d37986e25a5cf2ebb6da68->enter($__internal_10b1902867edbffcef220b0971c0dd78eb414f6020d37986e25a5cf2ebb6da68_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "javascript"));

        
        $__internal_10b1902867edbffcef220b0971c0dd78eb414f6020d37986e25a5cf2ebb6da68->leave($__internal_10b1902867edbffcef220b0971c0dd78eb414f6020d37986e25a5cf2ebb6da68_prof);

    }

    // line 31
    public function block_stylesheets($context, array $blocks = array())
    {
        $__internal_293b3e0ff62a95c1383db54b310b8cda5b13b76bb1efeb2c8dbe0ba719383929 = $this->env->getExtension("native_profiler");
        $__internal_293b3e0ff62a95c1383db54b310b8cda5b13b76bb1efeb2c8dbe0ba719383929->enter($__internal_293b3e0ff62a95c1383db54b310b8cda5b13b76bb1efeb2c8dbe0ba719383929_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "stylesheets"));

        // line 32
        echo "    ";
        // line 33
        echo "    <link rel=\"stylesheet\" href=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('asset')->getAssetUrl("bundles/framework/css/bootstrap.css"), "html", null, true);
        echo "\" type=\"text/css\" />
    ";
        
        $__internal_293b3e0ff62a95c1383db54b310b8cda5b13b76bb1efeb2c8dbe0ba719383929->leave($__internal_293b3e0ff62a95c1383db54b310b8cda5b13b76bb1efeb2c8dbe0ba719383929_prof);

    }

    public function getTemplateName()
    {
        return "myblog.base.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  125 => 33,  123 => 32,  117 => 31,  106 => 30,  95 => 28,  84 => 9,  68 => 35,  65 => 31,  63 => 30,  60 => 29,  58 => 28,  36 => 9,  26 => 1,);
    }
}
/* <!DOCTYPE>*/
/* <html lang="en">*/
/*     <head>*/
/*         <meta charset="UTF-8" />*/
/*         <meta name="viewport" content="width=device-width, initial-scale=1"/>*/
/*         <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">*/
/*  		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>*/
/*   		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>*/
/*         <title>{% block title %}{% endblock %}</title>*/
/*     </head>*/
/*     <body>*/
/*     <nav class="navbar navbar-default navbar-fixed-top" role="navigation">*/
/*   		<div class="container-fluid">*/
/* 			<ul class="nav navbar-nav">*/
/*                   <li><a href="/presentation">Acous<br><u class="fin-header">acous.secure@gmail.com</u></a></li>*/
/* 			</ul>*/
/*     		<!-- Collect the nav links, forms, and other content for toggling -->*/
/*     		<div class="sd-nav" id="bs-example-navbar-collapse-1">*/
/* 				 <ul class="nav navbar-nav list">*/
/*                       <li><a href="/">Home</a></li>*/
/*                       <li><a href="/articles">Articles</a></li>*/
/*                       <li><a href="/">Games</a></li>*/
/*     			</ul>*/
/*    			</div><!-- /.navbar-collapse -->*/
/*   		</div><!-- /.container-fluid -->*/
/* 	</nav>*/
/* 	<div class="entry-text-cont">*/
/*     {% block body %}{% endblock %}*/
/*     </div>*/
/*     {% block javascript %}{% endblock %}*/
/*     {% block stylesheets %}*/
/*     {#}<link rel="stylesheet" href="{{ asset('bundles/framework/css/front.css') }}" type="text/css" />{#}*/
/*     <link rel="stylesheet" href="{{ asset('bundles/framework/css/bootstrap.css') }}" type="text/css" />*/
/*     {% endblock %}*/
/*     </body>*/
/* */
/* */
/* */
/* */
/* */
/* */
/* */
/* */
/* </html>*/
