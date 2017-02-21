<?php

/* @WebProfiler/Collector/router.html.twig */
class __TwigTemplate_a35e3dc5da4b3e952008f4cf527e51ee48e550fdffe41a7b617c44f22c209550 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("@WebProfiler/Profiler/layout.html.twig", "@WebProfiler/Collector/router.html.twig", 1);
        $this->blocks = array(
            'toolbar' => array($this, 'block_toolbar'),
            'menu' => array($this, 'block_menu'),
            'panel' => array($this, 'block_panel'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "@WebProfiler/Profiler/layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_8e7cd65691ce125c0f3e180b7943c7f859c7388734017c9b9155a6417c5c23c5 = $this->env->getExtension("native_profiler");
        $__internal_8e7cd65691ce125c0f3e180b7943c7f859c7388734017c9b9155a6417c5c23c5->enter($__internal_8e7cd65691ce125c0f3e180b7943c7f859c7388734017c9b9155a6417c5c23c5_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@WebProfiler/Collector/router.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_8e7cd65691ce125c0f3e180b7943c7f859c7388734017c9b9155a6417c5c23c5->leave($__internal_8e7cd65691ce125c0f3e180b7943c7f859c7388734017c9b9155a6417c5c23c5_prof);

    }

    // line 3
    public function block_toolbar($context, array $blocks = array())
    {
        $__internal_07ac9805d50dd7b5c278075106ca227a90c6ea2e74dec7d87409edee1826c842 = $this->env->getExtension("native_profiler");
        $__internal_07ac9805d50dd7b5c278075106ca227a90c6ea2e74dec7d87409edee1826c842->enter($__internal_07ac9805d50dd7b5c278075106ca227a90c6ea2e74dec7d87409edee1826c842_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "toolbar"));

        
        $__internal_07ac9805d50dd7b5c278075106ca227a90c6ea2e74dec7d87409edee1826c842->leave($__internal_07ac9805d50dd7b5c278075106ca227a90c6ea2e74dec7d87409edee1826c842_prof);

    }

    // line 5
    public function block_menu($context, array $blocks = array())
    {
        $__internal_cecd27344637cf7c086534a2d4f5bc30d2c3c96158da1eba39bbacdde9fa02a8 = $this->env->getExtension("native_profiler");
        $__internal_cecd27344637cf7c086534a2d4f5bc30d2c3c96158da1eba39bbacdde9fa02a8->enter($__internal_cecd27344637cf7c086534a2d4f5bc30d2c3c96158da1eba39bbacdde9fa02a8_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "menu"));

        // line 6
        echo "<span class=\"label\">
    <span class=\"icon\">";
        // line 7
        echo twig_include($this->env, $context, "@WebProfiler/Icon/router.svg");
        echo "</span>
    <strong>Routing</strong>
</span>
";
        
        $__internal_cecd27344637cf7c086534a2d4f5bc30d2c3c96158da1eba39bbacdde9fa02a8->leave($__internal_cecd27344637cf7c086534a2d4f5bc30d2c3c96158da1eba39bbacdde9fa02a8_prof);

    }

    // line 12
    public function block_panel($context, array $blocks = array())
    {
        $__internal_b0bb141a0d6c98ee9c6b5533801d8a747ae787d1748dfd43a2d9312daa047153 = $this->env->getExtension("native_profiler");
        $__internal_b0bb141a0d6c98ee9c6b5533801d8a747ae787d1748dfd43a2d9312daa047153->enter($__internal_b0bb141a0d6c98ee9c6b5533801d8a747ae787d1748dfd43a2d9312daa047153_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "panel"));

        // line 13
        echo "    ";
        echo $this->env->getExtension('http_kernel')->renderFragment($this->env->getExtension('routing')->getPath("_profiler_router", array("token" => (isset($context["token"]) ? $context["token"] : $this->getContext($context, "token")))));
        echo "
";
        
        $__internal_b0bb141a0d6c98ee9c6b5533801d8a747ae787d1748dfd43a2d9312daa047153->leave($__internal_b0bb141a0d6c98ee9c6b5533801d8a747ae787d1748dfd43a2d9312daa047153_prof);

    }

    public function getTemplateName()
    {
        return "@WebProfiler/Collector/router.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  73 => 13,  67 => 12,  56 => 7,  53 => 6,  47 => 5,  36 => 3,  11 => 1,);
    }
}
/* {% extends '@WebProfiler/Profiler/layout.html.twig' %}*/
/* */
/* {% block toolbar %}{% endblock %}*/
/* */
/* {% block menu %}*/
/* <span class="label">*/
/*     <span class="icon">{{ include('@WebProfiler/Icon/router.svg') }}</span>*/
/*     <strong>Routing</strong>*/
/* </span>*/
/* {% endblock %}*/
/* */
/* {% block panel %}*/
/*     {{ render(path('_profiler_router', { token: token })) }}*/
/* {% endblock %}*/
/* */
