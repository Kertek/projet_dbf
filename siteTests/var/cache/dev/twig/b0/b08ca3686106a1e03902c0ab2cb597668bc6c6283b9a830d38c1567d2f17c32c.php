<?php

/* /default/show_article.html.twig */
class __TwigTemplate_91e290c0603db77bb667be66847abf050927f91eadd8a4276cab0753655b87cb extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("myblog.base.html.twig", "/default/show_article.html.twig", 1);
        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'body' => array($this, 'block_body'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "myblog.base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_0bfd03346b3b6b4d63a8c36644879fe69e884547be28f3c3ab8522d2ccbd247c = $this->env->getExtension("native_profiler");
        $__internal_0bfd03346b3b6b4d63a8c36644879fe69e884547be28f3c3ab8522d2ccbd247c->enter($__internal_0bfd03346b3b6b4d63a8c36644879fe69e884547be28f3c3ab8522d2ccbd247c_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/show_article.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_0bfd03346b3b6b4d63a8c36644879fe69e884547be28f3c3ab8522d2ccbd247c->leave($__internal_0bfd03346b3b6b4d63a8c36644879fe69e884547be28f3c3ab8522d2ccbd247c_prof);

    }

    // line 2
    public function block_title($context, array $blocks = array())
    {
        $__internal_821015b95722652ad5d43e1a307578eaf3cf8442a2d8c36f82fd6e88d10004d0 = $this->env->getExtension("native_profiler");
        $__internal_821015b95722652ad5d43e1a307578eaf3cf8442a2d8c36f82fd6e88d10004d0->enter($__internal_821015b95722652ad5d43e1a307578eaf3cf8442a2d8c36f82fd6e88d10004d0_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["article"]) ? $context["article"] : $this->getContext($context, "article")), "getTitle", array()), "html", null, true);
        
        $__internal_821015b95722652ad5d43e1a307578eaf3cf8442a2d8c36f82fd6e88d10004d0->leave($__internal_821015b95722652ad5d43e1a307578eaf3cf8442a2d8c36f82fd6e88d10004d0_prof);

    }

    // line 3
    public function block_body($context, array $blocks = array())
    {
        $__internal_9535c4d0a3b87e08dedf57e53f6d7ad853c2de2f9b889d4589cf2a611fcb8b13 = $this->env->getExtension("native_profiler");
        $__internal_9535c4d0a3b87e08dedf57e53f6d7ad853c2de2f9b889d4589cf2a611fcb8b13->enter($__internal_9535c4d0a3b87e08dedf57e53f6d7ad853c2de2f9b889d4589cf2a611fcb8b13_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 4
        echo "\t<br>";
        echo $this->getAttribute((isset($context["article"]) ? $context["article"] : $this->getContext($context, "article")), "getBody", array());
        echo "<br>
";
        
        $__internal_9535c4d0a3b87e08dedf57e53f6d7ad853c2de2f9b889d4589cf2a611fcb8b13->leave($__internal_9535c4d0a3b87e08dedf57e53f6d7ad853c2de2f9b889d4589cf2a611fcb8b13_prof);

    }

    public function getTemplateName()
    {
        return "/default/show_article.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  53 => 4,  47 => 3,  35 => 2,  11 => 1,);
    }
}
/* {% extends 'myblog.base.html.twig' %}*/
/* {% block title %}{{ article.getTitle }}{% endblock %}*/
/* {% block body %}*/
/* 	<br>{{ article.getBody|raw }}<br>*/
/* {% endblock %}*/
