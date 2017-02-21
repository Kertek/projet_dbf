<?php

/* @Twig/Exception/exception_full.html.twig */
class __TwigTemplate_5313570b6405e2f0d766ae6575eed159857508e13ed6d05ab064f103a992ba81 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("@Twig/layout.html.twig", "@Twig/Exception/exception_full.html.twig", 1);
        $this->blocks = array(
            'head' => array($this, 'block_head'),
            'title' => array($this, 'block_title'),
            'body' => array($this, 'block_body'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "@Twig/layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_fc46accadd2a941048d1f343be805c5c5e3e18c9f44ed9eb2dd4ac7d2328fe2f = $this->env->getExtension("native_profiler");
        $__internal_fc46accadd2a941048d1f343be805c5c5e3e18c9f44ed9eb2dd4ac7d2328fe2f->enter($__internal_fc46accadd2a941048d1f343be805c5c5e3e18c9f44ed9eb2dd4ac7d2328fe2f_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@Twig/Exception/exception_full.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_fc46accadd2a941048d1f343be805c5c5e3e18c9f44ed9eb2dd4ac7d2328fe2f->leave($__internal_fc46accadd2a941048d1f343be805c5c5e3e18c9f44ed9eb2dd4ac7d2328fe2f_prof);

    }

    // line 3
    public function block_head($context, array $blocks = array())
    {
        $__internal_2db3260173d8851a62555bcb799d208c7fdc05f6e65c8c764053b81c55cc7d57 = $this->env->getExtension("native_profiler");
        $__internal_2db3260173d8851a62555bcb799d208c7fdc05f6e65c8c764053b81c55cc7d57->enter($__internal_2db3260173d8851a62555bcb799d208c7fdc05f6e65c8c764053b81c55cc7d57_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "head"));

        // line 4
        echo "    <link href=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('request')->generateAbsoluteUrl($this->env->getExtension('asset')->getAssetUrl("bundles/framework/css/exception.css")), "html", null, true);
        echo "\" rel=\"stylesheet\" type=\"text/css\" media=\"all\" />
";
        
        $__internal_2db3260173d8851a62555bcb799d208c7fdc05f6e65c8c764053b81c55cc7d57->leave($__internal_2db3260173d8851a62555bcb799d208c7fdc05f6e65c8c764053b81c55cc7d57_prof);

    }

    // line 7
    public function block_title($context, array $blocks = array())
    {
        $__internal_203af9812844a4cfe8b062c566fe35e1a08d2a7ab952a7ba9e3c9bdd24d3d414 = $this->env->getExtension("native_profiler");
        $__internal_203af9812844a4cfe8b062c566fe35e1a08d2a7ab952a7ba9e3c9bdd24d3d414->enter($__internal_203af9812844a4cfe8b062c566fe35e1a08d2a7ab952a7ba9e3c9bdd24d3d414_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        // line 8
        echo "    ";
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["exception"]) ? $context["exception"] : $this->getContext($context, "exception")), "message", array()), "html", null, true);
        echo " (";
        echo twig_escape_filter($this->env, (isset($context["status_code"]) ? $context["status_code"] : $this->getContext($context, "status_code")), "html", null, true);
        echo " ";
        echo twig_escape_filter($this->env, (isset($context["status_text"]) ? $context["status_text"] : $this->getContext($context, "status_text")), "html", null, true);
        echo ")
";
        
        $__internal_203af9812844a4cfe8b062c566fe35e1a08d2a7ab952a7ba9e3c9bdd24d3d414->leave($__internal_203af9812844a4cfe8b062c566fe35e1a08d2a7ab952a7ba9e3c9bdd24d3d414_prof);

    }

    // line 11
    public function block_body($context, array $blocks = array())
    {
        $__internal_709dfb00a656bfbc0e3ea1a37ea6c06f2e4881c57f6f6ec46613c2bb390a9659 = $this->env->getExtension("native_profiler");
        $__internal_709dfb00a656bfbc0e3ea1a37ea6c06f2e4881c57f6f6ec46613c2bb390a9659->enter($__internal_709dfb00a656bfbc0e3ea1a37ea6c06f2e4881c57f6f6ec46613c2bb390a9659_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 12
        echo "    ";
        $this->loadTemplate("@Twig/Exception/exception.html.twig", "@Twig/Exception/exception_full.html.twig", 12)->display($context);
        
        $__internal_709dfb00a656bfbc0e3ea1a37ea6c06f2e4881c57f6f6ec46613c2bb390a9659->leave($__internal_709dfb00a656bfbc0e3ea1a37ea6c06f2e4881c57f6f6ec46613c2bb390a9659_prof);

    }

    public function getTemplateName()
    {
        return "@Twig/Exception/exception_full.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  78 => 12,  72 => 11,  58 => 8,  52 => 7,  42 => 4,  36 => 3,  11 => 1,);
    }
}
/* {% extends '@Twig/layout.html.twig' %}*/
/* */
/* {% block head %}*/
/*     <link href="{{ absolute_url(asset('bundles/framework/css/exception.css')) }}" rel="stylesheet" type="text/css" media="all" />*/
/* {% endblock %}*/
/* */
/* {% block title %}*/
/*     {{ exception.message }} ({{ status_code }} {{ status_text }})*/
/* {% endblock %}*/
/* */
/* {% block body %}*/
/*     {% include '@Twig/Exception/exception.html.twig' %}*/
/* {% endblock %}*/
/* */
