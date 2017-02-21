<?php

/* /default/premier.html.twig */
class __TwigTemplate_4d5def05b70bf16c42d628779daeda9d1533eccf33689c8514f3fbdb061bcb2f extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("myblog.base.html.twig", "/default/premier.html.twig", 1);
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
        $__internal_2a6685b387eb5e4611bd0c2de71642a94756fbb3a77fe3076341cd701c732e26 = $this->env->getExtension("native_profiler");
        $__internal_2a6685b387eb5e4611bd0c2de71642a94756fbb3a77fe3076341cd701c732e26->enter($__internal_2a6685b387eb5e4611bd0c2de71642a94756fbb3a77fe3076341cd701c732e26_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/premier.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_2a6685b387eb5e4611bd0c2de71642a94756fbb3a77fe3076341cd701c732e26->leave($__internal_2a6685b387eb5e4611bd0c2de71642a94756fbb3a77fe3076341cd701c732e26_prof);

    }

    // line 2
    public function block_title($context, array $blocks = array())
    {
        $__internal_110948f9fc76e142b74ea450adc927ea40d9258be5f878b295eb28e1a050e488 = $this->env->getExtension("native_profiler");
        $__internal_110948f9fc76e142b74ea450adc927ea40d9258be5f878b295eb28e1a050e488->enter($__internal_110948f9fc76e142b74ea450adc927ea40d9258be5f878b295eb28e1a050e488_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo "Accueil";
        
        $__internal_110948f9fc76e142b74ea450adc927ea40d9258be5f878b295eb28e1a050e488->leave($__internal_110948f9fc76e142b74ea450adc927ea40d9258be5f878b295eb28e1a050e488_prof);

    }

    // line 4
    public function block_body($context, array $blocks = array())
    {
        $__internal_82cfd1f16ddbefedc57bc3e4ed1d630b5f4dc0a58d2e965edc333f4e2e6a771b = $this->env->getExtension("native_profiler");
        $__internal_82cfd1f16ddbefedc57bc3e4ed1d630b5f4dc0a58d2e965edc333f4e2e6a771b->enter($__internal_82cfd1f16ddbefedc57bc3e4ed1d630b5f4dc0a58d2e965edc333f4e2e6a771b_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 5
        echo "<div class=\"text-center\">
\t\t<ul>
        ";
        // line 7
        $context['_parent'] = $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["articles"]) ? $context["articles"] : $this->getContext($context, "articles")));
        foreach ($context['_seq'] as $context["_key"] => $context["article"]) {
            // line 8
            echo "        \t<li class=\"actu\">
        \t<h1><a href=\"";
            // line 9
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("show_article", array("id" => $this->getAttribute($context["article"], "getId", array()))), "html", null, true);
            echo "\">article n°";
            echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getId", array()), "html", null, true);
            echo ": ";
            echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getTitle", array()), "html", null, true);
            echo "</a>
            -- ";
            // line 10
            echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getDate", array()), "html", null, true);
            echo "</h1>
            <p class=article>";
            // line 11
            echo $this->getAttribute($context["article"], "getBody", array());
            echo "</p>
            </li>
        ";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['article'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 13
        echo " 
        </ul>
</div>
";
        
        $__internal_82cfd1f16ddbefedc57bc3e4ed1d630b5f4dc0a58d2e965edc333f4e2e6a771b->leave($__internal_82cfd1f16ddbefedc57bc3e4ed1d630b5f4dc0a58d2e965edc333f4e2e6a771b_prof);

    }

    public function getTemplateName()
    {
        return "/default/premier.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  85 => 13,  76 => 11,  72 => 10,  64 => 9,  61 => 8,  57 => 7,  53 => 5,  47 => 4,  35 => 2,  11 => 1,);
    }
}
/* {% extends 'myblog.base.html.twig' %}*/
/* {% block title %}Accueil{% endblock %}*/
/* */
/* {% block body %}*/
/* <div class="text-center">*/
/* 		<ul>*/
/*         {% for article in articles %}*/
/*         	<li class="actu">*/
/*         	<h1><a href="{{ path('show_article', { 'id': article.getId }) }}">article n°{{ article.getId }}: {{ article.getTitle }}</a>*/
/*             -- {{ article.getDate }}</h1>*/
/*             <p class=article>{{ article.getBody|raw }}</p>*/
/*             </li>*/
/*         {% endfor %} */
/*         </ul>*/
/* </div>*/
/* {% endblock %}*/
/* */
