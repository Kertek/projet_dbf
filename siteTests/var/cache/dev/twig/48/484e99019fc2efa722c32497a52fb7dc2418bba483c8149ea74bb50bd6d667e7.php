<?php

/* /default/articles.html.twig */
class __TwigTemplate_795cf004b8e28f7d5c2c1e7a21da0933704e234124ec351aa2fb25f5748e943c extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("myblog.base.html.twig", "/default/articles.html.twig", 1);
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
        $__internal_1bcf9fc09e42cbf6be55af7e33d0418f9dc392e95ea04a185f79db7e966f2fde = $this->env->getExtension("native_profiler");
        $__internal_1bcf9fc09e42cbf6be55af7e33d0418f9dc392e95ea04a185f79db7e966f2fde->enter($__internal_1bcf9fc09e42cbf6be55af7e33d0418f9dc392e95ea04a185f79db7e966f2fde_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/articles.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_1bcf9fc09e42cbf6be55af7e33d0418f9dc392e95ea04a185f79db7e966f2fde->leave($__internal_1bcf9fc09e42cbf6be55af7e33d0418f9dc392e95ea04a185f79db7e966f2fde_prof);

    }

    // line 2
    public function block_title($context, array $blocks = array())
    {
        $__internal_53648124f500b6c7e6fd13398661b322c1a77dbbf5ec220fe5c8b80402733c0b = $this->env->getExtension("native_profiler");
        $__internal_53648124f500b6c7e6fd13398661b322c1a77dbbf5ec220fe5c8b80402733c0b->enter($__internal_53648124f500b6c7e6fd13398661b322c1a77dbbf5ec220fe5c8b80402733c0b_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo "Articles";
        
        $__internal_53648124f500b6c7e6fd13398661b322c1a77dbbf5ec220fe5c8b80402733c0b->leave($__internal_53648124f500b6c7e6fd13398661b322c1a77dbbf5ec220fe5c8b80402733c0b_prof);

    }

    // line 3
    public function block_body($context, array $blocks = array())
    {
        $__internal_945468e86b776b4f3c0010d524cc6a78134b92971806d6798c947d63efa642f9 = $this->env->getExtension("native_profiler");
        $__internal_945468e86b776b4f3c0010d524cc6a78134b92971806d6798c947d63efa642f9->enter($__internal_945468e86b776b4f3c0010d524cc6a78134b92971806d6798c947d63efa642f9_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 4
        echo "\t<div class=\"text-center\">
\t<div class=\"row-fluid text-blanc gras\">
\t";
        // line 6
        echo         $this->env->getExtension('form')->renderer->renderBlock((isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")), 'form_start');
        echo "
    ";
        // line 7
        echo $this->env->getExtension('form')->renderer->searchAndRenderBlock((isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")), 'widget', array("attr" => array("class" => "navbar-form navbar-center")));
        echo "
    ";
        // line 8
        echo         $this->env->getExtension('form')->renderer->renderBlock((isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")), 'form_end');
        echo "
    </div>
    <div class=\"row-fluid text-blanc gras\">
\t";
        // line 11
        if ((twig_length_filter($this->env, (isset($context["articles"]) ? $context["articles"] : $this->getContext($context, "articles"))) == 0)) {
            // line 12
            echo "\t\tDésolé, il n'y a aucun article correspondant à votre recherche.
\t";
        } else {
            // line 14
            echo "\t\t\t<p class=\"nombre\">";
            echo twig_escape_filter($this->env, twig_length_filter($this->env, (isset($context["articles"]) ? $context["articles"] : $this->getContext($context, "articles"))), "html", null, true);
            echo " ";
            echo (((twig_length_filter($this->env, (isset($context["articles"]) ? $context["articles"] : $this->getContext($context, "articles"))) == 1)) ? ("article trouvé") : ("articles trouvés"));
            echo ".</p>
    \t\t<ul>
        \t";
            // line 16
            $context['_parent'] = $context;
            $context['_seq'] = twig_ensure_traversable(twig_reverse_filter($this->env, (isset($context["articles"]) ? $context["articles"] : $this->getContext($context, "articles"))));
            foreach ($context['_seq'] as $context["_key"] => $context["article"]) {
                // line 17
                echo "        \t\t<li>
        \t\t<a href=\"";
                // line 18
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("show_article", array("id" => $this->getAttribute($context["article"], "getId", array()))), "html", null, true);
                echo "\">article n°";
                echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getId", array()), "html", null, true);
                echo ": ";
                echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getTitle", array()), "html", null, true);
                echo "</a>
        \t\t-- ";
                // line 19
                echo twig_escape_filter($this->env, $this->getAttribute($context["article"], "getDate", array()), "html", null, true);
                echo "
        \t\t</li>
        \t";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['_key'], $context['article'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 21
            echo "\t
        \t</ul>
        </div>
    ";
        }
        // line 25
        echo "    </div>
";
        
        $__internal_945468e86b776b4f3c0010d524cc6a78134b92971806d6798c947d63efa642f9->leave($__internal_945468e86b776b4f3c0010d524cc6a78134b92971806d6798c947d63efa642f9_prof);

    }

    public function getTemplateName()
    {
        return "/default/articles.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  115 => 25,  109 => 21,  100 => 19,  92 => 18,  89 => 17,  85 => 16,  77 => 14,  73 => 12,  71 => 11,  65 => 8,  61 => 7,  57 => 6,  53 => 4,  47 => 3,  35 => 2,  11 => 1,);
    }
}
/* {% extends 'myblog.base.html.twig' %}*/
/* {% block title %}Articles{% endblock %}*/
/* {% block body %}*/
/* 	<div class="text-center">*/
/* 	<div class="row-fluid text-blanc gras">*/
/* 	{{ form_start(form) }}*/
/*     {{ form_widget(form, { 'attr': {'class': 'navbar-form navbar-center'}}) }}*/
/*     {{ form_end(form) }}*/
/*     </div>*/
/*     <div class="row-fluid text-blanc gras">*/
/* 	{% if articles|length == 0 %}*/
/* 		Désolé, il n'y a aucun article correspondant à votre recherche.*/
/* 	{% else %}*/
/* 			<p class="nombre">{{ articles|length }} {{ articles|length==1? "article trouvé":"articles trouvés" }}.</p>*/
/*     		<ul>*/
/*         	{% for article in articles|reverse  %}*/
/*         		<li>*/
/*         		<a href="{{ path('show_article', { 'id': article.getId }) }}">article n°{{ article.getId }}: {{ article.getTitle }}</a>*/
/*         		-- {{ article.getDate }}*/
/*         		</li>*/
/*         	{% endfor %}	*/
/*         	</ul>*/
/*         </div>*/
/*     {% endif %}*/
/*     </div>*/
/* {% endblock %}*/
