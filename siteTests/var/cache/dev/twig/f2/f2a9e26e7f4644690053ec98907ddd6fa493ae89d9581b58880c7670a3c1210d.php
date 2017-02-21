<?php

/* /default/presentation.html.twig */
class __TwigTemplate_8712dc413f07eea8ff7281234ca115ca020c9ee88a40c549aaea747436a67ef0 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("myblog.base.html.twig", "/default/presentation.html.twig", 1);
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
        $__internal_81f90702481c3a7aa4b5a5bd5f67f8c6830be2980b927f58b770405595651e0a = $this->env->getExtension("native_profiler");
        $__internal_81f90702481c3a7aa4b5a5bd5f67f8c6830be2980b927f58b770405595651e0a->enter($__internal_81f90702481c3a7aa4b5a5bd5f67f8c6830be2980b927f58b770405595651e0a_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "/default/presentation.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_81f90702481c3a7aa4b5a5bd5f67f8c6830be2980b927f58b770405595651e0a->leave($__internal_81f90702481c3a7aa4b5a5bd5f67f8c6830be2980b927f58b770405595651e0a_prof);

    }

    // line 2
    public function block_title($context, array $blocks = array())
    {
        $__internal_79a962081eb40282c94a03bb28b1dcc98b6d273456a18bb73060cb63e30be54e = $this->env->getExtension("native_profiler");
        $__internal_79a962081eb40282c94a03bb28b1dcc98b6d273456a18bb73060cb63e30be54e->enter($__internal_79a962081eb40282c94a03bb28b1dcc98b6d273456a18bb73060cb63e30be54e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo "Accueil";
        
        $__internal_79a962081eb40282c94a03bb28b1dcc98b6d273456a18bb73060cb63e30be54e->leave($__internal_79a962081eb40282c94a03bb28b1dcc98b6d273456a18bb73060cb63e30be54e_prof);

    }

    // line 4
    public function block_body($context, array $blocks = array())
    {
        $__internal_9d7b49c3cff09b2e65e9cafa61119ae8f133dabc5ce77dbc04b77b31df5d8eeb = $this->env->getExtension("native_profiler");
        $__internal_9d7b49c3cff09b2e65e9cafa61119ae8f133dabc5ce77dbc04b77b31df5d8eeb->enter($__internal_9d7b49c3cff09b2e65e9cafa61119ae8f133dabc5ce77dbc04b77b31df5d8eeb_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 5
        echo "<div class=\"text-center\"> 
        <p>
        Salut salut, voici mon premier site web codé from scratch.<br>
        Vous y trouverez des articles que j'aurrais rédigés moi même.<br> 
        Ceux-ci devraient traîter de <b>sécurité informatique</b> mais peut-être d'autres trucs aussi :).<br>
        Je ne suis pas un pro, et ces articles correspondent à l'aboutissement d'un travail<br> de <b>recherches personnelles</b> qui peut donc contenir des erreurs.<br> 
        Si vous en trouvez, dites le moi par mail, please<br> cela m'interresse beaucoup.<br>
        <br>
        Je mettrais de temps en temps, des challenges dans la rublrique \"Games\" 
        <br>
        </p>
</div>

<div class=\"article\">
\t<h2>SQL injections: understanding with SQLmap</h2>
\t<h3>Contents:</h3>
\t<ol style=\"list-style-type:upper-roman;\">
\t\t<li>Dumping databases</li>
\t\t<ol style=\"list-style-type:arabic-numbers;\">
\t\t\t<li>Basic injections</li>
\t\t\t<li>Almost blind injections</li>
\t\t\t<li>Blind injections</li>
\t\t</ol>
\t\t<li>System calls</li>
\t\t<ol style=\"list-style-type:arabic-numbers;\">
\t\t\t<li>Reading</li>
\t\t\t<li>Writing</li>
\t\t\t<li>Backdoors</li>
\t\t</ol>
\t\t<li>Mysql's important functions</li>
\t\t<li>Other DBMS</li>
\t\t
\t</ol>
\t<h3>Introduction</h3>
\t<p>To start, let's say that SQL injections aren’t security threats due to DBMS. 
\tIn fact the main reason of this kind of threat is a wrong management of input/output 
\tby the Web application. As such, it is up to you to secure your application ^^ 
\t(easier said than done).</p>
\t<p>SQLmap is a tool created by Bernardo Damele and Miroslav Stampa. 
\tIt is coded in Python and allows the users to automate SQL injections. 
\tSQLmap works on differents DBMS such as: MySQL, Oracle, PostgreSQL, 
\tMicrosoft SQL server, Microsoft access, SQLite, Firebird, Sybase and SAP MaxDB. 
\t<b>Here we will mostly talk about MySQL</b></p>
\t<h4>SQLmap's organisation</h4>
\t<p>plugins: modules for specific DBMS.<br>
\tShell: stagers and backdoors writen in php, jsp et asp.<br>
\tXml: queries et paylods (there is the knowledge of SQLmap ^^).<br>
\tREM : SQLmap can use Métasploit.</p>
\t<ol style=\"list-style-type:upper-roman;\">
\t\t<h3><li>Dumping databases</li></h3>
        \t<p>There are 3 main kinds of SQL injections:
        \t<ul>
        \t\t<li>Basic injections</li>
\t\t\t\t<li>Almost blind injections</li>
\t\t\t\t<li>Blind injections</li>
        \t</ul>
        \t<b>To train yourself, you can install DVWA (Damn Vulnerable Web Application) on a virtual machine.</b></p><br>
        \t<ol style=\"list-style-type:arabic-numbers;\">
    \t\t\t<h4><li>Basic injections</li></h4>
                \t<p>Here, the results of your search are directly shown in the server answers.</p>
                
                    <p>For example, here is a form which allows you to join an id: 
                    <form>
                    \tid:
                    \t<input type=\"text\"/>
                    </form>
                    When you enter a number (let's enter 1)
                    the server answers:<br> 
                    
                    <code>first_name=fist_name1<br>last_name=last_name1</code></p>
                    <p>A useful way to dump databases is to use <code>UNION</code> instruction
                    (be careful, you had to respect output dimensions).</p>
                    <p>If you enter in the form:
                    <code>1' UNION select first_name,password from users -- </code>
                     we get:<br>
                    <code>first_name: user1<br>last_name: user1_pass<br><br>first_name: user2<br>last_name: user2_pass</code></p>
                    <ul>
                    REM:
                    \t<li>\"-- \" (notice the space at the end) is really important. It is use to comment SQL code. Here, we use it to 
                    \tavoid errors due to the rest of the default SQL query that the server send.</li>
                    \t<li>If you don't care about the first_name field, you can inject:<br> <code>1' UNION select <b>NULL</b>,password from users -- </code></li>
               \t\t</ul>    
                    <p>To achieve this kind of injections using SQLmap:<br>
                    <code>\$&gt; ./sqlmap.py -u \"http://lien_du_site\" --cookie=\"cookie1=value1; cookie2=value2\" --technique=U --dump</code></p>
                    <p>You may wonder why it is useful to automate this kind of attacks. 
                    It seems simple but the real problem is to find the names of database’s tables and data fields.
                    Moreover, it’s easy for a developer to create little rules to secure his application. 
                    An approach is to escape special characters. In fact, it is <b>not really helpful</b> 
                    because if you enter the unicode translation of your injection, special characters 
                    will not be escaped but the request will be interpreted. 
                    So if you use SQLmap, no need to search one hour for this kind of things.</p>
                    <p><u>REM:</u>If a form sends data through <code>POST</code> method, you must change 
                    SQLmap options like this:<br>
                    <code>\$&gt; ./sqlmap.py -u \"http://lien_du_site\" --cookie=\"cookie1=value1; cookie2=value2\" --method=POST --data=\"data envoyé dans le post\" --technique=U --dump</code></p><br>

\t\t\t\t<h4><li>Almost blind injections</li></h4>
                \t<p>Here, server’s answers didn’t give any data from the database back. 
                \tHowever, it is not totally blind because you can see in the answer if the SQL query has 
                \tbeen accepted. For example, it can be written: <code>Your query has been accepted</code> 
                \tor the language of the answer changes.</p>
                \t<p>As a consequence, we must send a lot of requests to find the useful data.</p>
                \t<p>Example:<br>
                \there is a form which allows you to join an id:
                \t<form>
                    \tid:
                    \t<input type=\"text\"/>
                    </form>
                    While testing some inputs, we see that the id must be included between 1 and 5.
                     We inject: <code>40' OR ascii(substring(password,1,1))>25 -- </code>.</p>
                    <p>REM:
                    \t<ul>
                    \t\t<li><code>ascii()</code> translate a character to his ascii code.</li> 
                    \t\t<li><code>substring</code> return a part of a string (<code>substring(string,start,size)</code>)</li>
                    \t</ul>
                    \t</p>
                \t
                \t<p>So if the query is accepted, we know, in our example, that there is a password which start by a character whose ascii code is greater than 25. 
\t\t\t\t\tAs such we can find all the password using dichotomy.</p>
                \t<p>Rem:<br> 
                \t<ul>
                    \t<li>An ascii code is always positif. 
                    \tSo we can use it to find the names of tables and fields. 
                    \tStill in the same example, we can think that there is a field called
                    \t<code>user</code>. We inject <code>40' OR ascii(substring(user,1,1))>0 -- </code>.
                    \tIf this is accepted, we know that there is a field starting with a “u”. 
                    \tLet’s try for “s” and so on.   
                    \t</li>
                    \t<li>We also have access to tables differing from the default one. 
                    \tFor example if the form looks in the <code>Id</code> table but that the useful 
                    \tinformations are in <code>Users</code> then we can inject:
\t\t\t\t\t\t<code>1' AND ASCII(SUBSTRING((SELECT password FROM users OFFSET 0 LIMIT 1) , 1 , 1))>25 -- </code> .
                    \t</li>
                \t</ul>
                \t</p><br>
\t\t\t\t<h4><li>Blind injections</li></h4>
                \t<p>Here you are totally blind, there is no data in the server’s answer.</p>
                \t<p>In this case, we had to use the period of time that the server need to answer to dump data. 
\t\t\t\t\tWe can use the <code>SLEEP</code> instruction to play with this period. Let’s give an example: 
                \t</p>
                \t<p>Example:<br>
                \tStill the same ^^.
                \t<form>
                    \tid:
                    \t<input type=\"text\"/>
                    </form>
                    Whatever the input is, the server answer “OK”.</p>
                    <p>We can inject <code>40' OR IF ( ascii(substring(password,1,1))>25, SLEEP(5), false) -- </code>. 
                    So if the server take 5 seconds to answer, it means that the query was accepted and
                    that there is a password which begin with a character which has a ascii code greater 
                    than 25. We can find the entire password using dichotomy.</p>
                \t<p><u>Be careful:</u> It is really slow and it can easily be clouded by a disrupted network.  
                \t</p>
                \t
                \t<p>SQlmap is able to use this kind of injection and has a check system to avoid false positive.
                \tBut even for SQLmap this kind of attacks is very slow. A useful way to increase its speed is to 
                \tfind the tables and columns names befor. For this purpose, you can use SQLmap like this:<br>
                \t<ul style=\"list-style-type:arabic-numbers;\">
                \t\tWe can dump all tables to see wich is interresting.
                \t\t<li>
                \t\t\t<code>\$&gt; ./sqlmap -u \"http://lien_du_site\" –cookie=\"cookie1=value1; cookie2=value2\" --tables</code>
                \t\t</li>
                \t\tWe can the dump all columns of the choosen table to choose the interresting one.
                \t\t<li>
                \t\t\t<code>\$&gt; ./sqlmap -u \"http://lien_du_site\" –cookie=\"cookie1=value1; cookie2=value2\" -T \"table\" --columns</code>
                \t\t</li>
                \t\tFinally we dump the data.
                \t\t<li>
                \t\t\t<code>\$&gt; ./sqlmap.py -u \"http://lien_du_site\" –cookie=\"cookie1=value1; cookie2=value2\" -C colonne1 -T
                \t\t\ttable1 -- dump </code><br>
                \t\t</li>
                \t</ul>
                \tThis way we don't wait for tables we don't care.<br>
                \tIt is even better to guess the name of the tables and columns and to run the third command line
                \tbut you are right, it is harder.
                \t
                    </p>
\t\t\t</ol>
    \t\t<h3><li>System calls</li></h3>
    
</div>
";
        
        $__internal_9d7b49c3cff09b2e65e9cafa61119ae8f133dabc5ce77dbc04b77b31df5d8eeb->leave($__internal_9d7b49c3cff09b2e65e9cafa61119ae8f133dabc5ce77dbc04b77b31df5d8eeb_prof);

    }

    public function getTemplateName()
    {
        return "/default/presentation.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  53 => 5,  47 => 4,  35 => 2,  11 => 1,);
    }
}
/* {% extends 'myblog.base.html.twig' %}*/
/* {% block title %}Accueil{% endblock %}*/
/* */
/* {% block body %}*/
/* <div class="text-center"> */
/*         <p>*/
/*         Salut salut, voici mon premier site web codé from scratch.<br>*/
/*         Vous y trouverez des articles que j'aurrais rédigés moi même.<br> */
/*         Ceux-ci devraient traîter de <b>sécurité informatique</b> mais peut-être d'autres trucs aussi :).<br>*/
/*         Je ne suis pas un pro, et ces articles correspondent à l'aboutissement d'un travail<br> de <b>recherches personnelles</b> qui peut donc contenir des erreurs.<br> */
/*         Si vous en trouvez, dites le moi par mail, please<br> cela m'interresse beaucoup.<br>*/
/*         <br>*/
/*         Je mettrais de temps en temps, des challenges dans la rublrique "Games" */
/*         <br>*/
/*         </p>*/
/* </div>*/
/* */
/* <div class="article">*/
/* 	<h2>SQL injections: understanding with SQLmap</h2>*/
/* 	<h3>Contents:</h3>*/
/* 	<ol style="list-style-type:upper-roman;">*/
/* 		<li>Dumping databases</li>*/
/* 		<ol style="list-style-type:arabic-numbers;">*/
/* 			<li>Basic injections</li>*/
/* 			<li>Almost blind injections</li>*/
/* 			<li>Blind injections</li>*/
/* 		</ol>*/
/* 		<li>System calls</li>*/
/* 		<ol style="list-style-type:arabic-numbers;">*/
/* 			<li>Reading</li>*/
/* 			<li>Writing</li>*/
/* 			<li>Backdoors</li>*/
/* 		</ol>*/
/* 		<li>Mysql's important functions</li>*/
/* 		<li>Other DBMS</li>*/
/* 		*/
/* 	</ol>*/
/* 	<h3>Introduction</h3>*/
/* 	<p>To start, let's say that SQL injections aren’t security threats due to DBMS. */
/* 	In fact the main reason of this kind of threat is a wrong management of input/output */
/* 	by the Web application. As such, it is up to you to secure your application ^^ */
/* 	(easier said than done).</p>*/
/* 	<p>SQLmap is a tool created by Bernardo Damele and Miroslav Stampa. */
/* 	It is coded in Python and allows the users to automate SQL injections. */
/* 	SQLmap works on differents DBMS such as: MySQL, Oracle, PostgreSQL, */
/* 	Microsoft SQL server, Microsoft access, SQLite, Firebird, Sybase and SAP MaxDB. */
/* 	<b>Here we will mostly talk about MySQL</b></p>*/
/* 	<h4>SQLmap's organisation</h4>*/
/* 	<p>plugins: modules for specific DBMS.<br>*/
/* 	Shell: stagers and backdoors writen in php, jsp et asp.<br>*/
/* 	Xml: queries et paylods (there is the knowledge of SQLmap ^^).<br>*/
/* 	REM : SQLmap can use Métasploit.</p>*/
/* 	<ol style="list-style-type:upper-roman;">*/
/* 		<h3><li>Dumping databases</li></h3>*/
/*         	<p>There are 3 main kinds of SQL injections:*/
/*         	<ul>*/
/*         		<li>Basic injections</li>*/
/* 				<li>Almost blind injections</li>*/
/* 				<li>Blind injections</li>*/
/*         	</ul>*/
/*         	<b>To train yourself, you can install DVWA (Damn Vulnerable Web Application) on a virtual machine.</b></p><br>*/
/*         	<ol style="list-style-type:arabic-numbers;">*/
/*     			<h4><li>Basic injections</li></h4>*/
/*                 	<p>Here, the results of your search are directly shown in the server answers.</p>*/
/*                 */
/*                     <p>For example, here is a form which allows you to join an id: */
/*                     <form>*/
/*                     	id:*/
/*                     	<input type="text"/>*/
/*                     </form>*/
/*                     When you enter a number (let's enter 1)*/
/*                     the server answers:<br> */
/*                     */
/*                     <code>first_name=fist_name1<br>last_name=last_name1</code></p>*/
/*                     <p>A useful way to dump databases is to use <code>UNION</code> instruction*/
/*                     (be careful, you had to respect output dimensions).</p>*/
/*                     <p>If you enter in the form:*/
/*                     <code>1' UNION select first_name,password from users -- </code>*/
/*                      we get:<br>*/
/*                     <code>first_name: user1<br>last_name: user1_pass<br><br>first_name: user2<br>last_name: user2_pass</code></p>*/
/*                     <ul>*/
/*                     REM:*/
/*                     	<li>"-- " (notice the space at the end) is really important. It is use to comment SQL code. Here, we use it to */
/*                     	avoid errors due to the rest of the default SQL query that the server send.</li>*/
/*                     	<li>If you don't care about the first_name field, you can inject:<br> <code>1' UNION select <b>NULL</b>,password from users -- </code></li>*/
/*                		</ul>    */
/*                     <p>To achieve this kind of injections using SQLmap:<br>*/
/*                     <code>$&gt; ./sqlmap.py -u "http://lien_du_site" --cookie="cookie1=value1; cookie2=value2" --technique=U --dump</code></p>*/
/*                     <p>You may wonder why it is useful to automate this kind of attacks. */
/*                     It seems simple but the real problem is to find the names of database’s tables and data fields.*/
/*                     Moreover, it’s easy for a developer to create little rules to secure his application. */
/*                     An approach is to escape special characters. In fact, it is <b>not really helpful</b> */
/*                     because if you enter the unicode translation of your injection, special characters */
/*                     will not be escaped but the request will be interpreted. */
/*                     So if you use SQLmap, no need to search one hour for this kind of things.</p>*/
/*                     <p><u>REM:</u>If a form sends data through <code>POST</code> method, you must change */
/*                     SQLmap options like this:<br>*/
/*                     <code>$&gt; ./sqlmap.py -u "http://lien_du_site" --cookie="cookie1=value1; cookie2=value2" --method=POST --data="data envoyé dans le post" --technique=U --dump</code></p><br>*/
/* */
/* 				<h4><li>Almost blind injections</li></h4>*/
/*                 	<p>Here, server’s answers didn’t give any data from the database back. */
/*                 	However, it is not totally blind because you can see in the answer if the SQL query has */
/*                 	been accepted. For example, it can be written: <code>Your query has been accepted</code> */
/*                 	or the language of the answer changes.</p>*/
/*                 	<p>As a consequence, we must send a lot of requests to find the useful data.</p>*/
/*                 	<p>Example:<br>*/
/*                 	here is a form which allows you to join an id:*/
/*                 	<form>*/
/*                     	id:*/
/*                     	<input type="text"/>*/
/*                     </form>*/
/*                     While testing some inputs, we see that the id must be included between 1 and 5.*/
/*                      We inject: <code>40' OR ascii(substring(password,1,1))>25 -- </code>.</p>*/
/*                     <p>REM:*/
/*                     	<ul>*/
/*                     		<li><code>ascii()</code> translate a character to his ascii code.</li> */
/*                     		<li><code>substring</code> return a part of a string (<code>substring(string,start,size)</code>)</li>*/
/*                     	</ul>*/
/*                     	</p>*/
/*                 	*/
/*                 	<p>So if the query is accepted, we know, in our example, that there is a password which start by a character whose ascii code is greater than 25. */
/* 					As such we can find all the password using dichotomy.</p>*/
/*                 	<p>Rem:<br> */
/*                 	<ul>*/
/*                     	<li>An ascii code is always positif. */
/*                     	So we can use it to find the names of tables and fields. */
/*                     	Still in the same example, we can think that there is a field called*/
/*                     	<code>user</code>. We inject <code>40' OR ascii(substring(user,1,1))>0 -- </code>.*/
/*                     	If this is accepted, we know that there is a field starting with a “u”. */
/*                     	Let’s try for “s” and so on.   */
/*                     	</li>*/
/*                     	<li>We also have access to tables differing from the default one. */
/*                     	For example if the form looks in the <code>Id</code> table but that the useful */
/*                     	informations are in <code>Users</code> then we can inject:*/
/* 						<code>1' AND ASCII(SUBSTRING((SELECT password FROM users OFFSET 0 LIMIT 1) , 1 , 1))>25 -- </code> .*/
/*                     	</li>*/
/*                 	</ul>*/
/*                 	</p><br>*/
/* 				<h4><li>Blind injections</li></h4>*/
/*                 	<p>Here you are totally blind, there is no data in the server’s answer.</p>*/
/*                 	<p>In this case, we had to use the period of time that the server need to answer to dump data. */
/* 					We can use the <code>SLEEP</code> instruction to play with this period. Let’s give an example: */
/*                 	</p>*/
/*                 	<p>Example:<br>*/
/*                 	Still the same ^^.*/
/*                 	<form>*/
/*                     	id:*/
/*                     	<input type="text"/>*/
/*                     </form>*/
/*                     Whatever the input is, the server answer “OK”.</p>*/
/*                     <p>We can inject <code>40' OR IF ( ascii(substring(password,1,1))>25, SLEEP(5), false) -- </code>. */
/*                     So if the server take 5 seconds to answer, it means that the query was accepted and*/
/*                     that there is a password which begin with a character which has a ascii code greater */
/*                     than 25. We can find the entire password using dichotomy.</p>*/
/*                 	<p><u>Be careful:</u> It is really slow and it can easily be clouded by a disrupted network.  */
/*                 	</p>*/
/*                 	*/
/*                 	<p>SQlmap is able to use this kind of injection and has a check system to avoid false positive.*/
/*                 	But even for SQLmap this kind of attacks is very slow. A useful way to increase its speed is to */
/*                 	find the tables and columns names befor. For this purpose, you can use SQLmap like this:<br>*/
/*                 	<ul style="list-style-type:arabic-numbers;">*/
/*                 		We can dump all tables to see wich is interresting.*/
/*                 		<li>*/
/*                 			<code>$&gt; ./sqlmap -u "http://lien_du_site" –cookie="cookie1=value1; cookie2=value2" --tables</code>*/
/*                 		</li>*/
/*                 		We can the dump all columns of the choosen table to choose the interresting one.*/
/*                 		<li>*/
/*                 			<code>$&gt; ./sqlmap -u "http://lien_du_site" –cookie="cookie1=value1; cookie2=value2" -T "table" --columns</code>*/
/*                 		</li>*/
/*                 		Finally we dump the data.*/
/*                 		<li>*/
/*                 			<code>$&gt; ./sqlmap.py -u "http://lien_du_site" –cookie="cookie1=value1; cookie2=value2" -C colonne1 -T*/
/*                 			table1 -- dump </code><br>*/
/*                 		</li>*/
/*                 	</ul>*/
/*                 	This way we don't wait for tables we don't care.<br>*/
/*                 	It is even better to guess the name of the tables and columns and to run the third command line*/
/*                 	but you are right, it is harder.*/
/*                 	*/
/*                     </p>*/
/* 			</ol>*/
/*     		<h3><li>System calls</li></h3>*/
/*     */
/* </div>*/
/* {% endblock %}*/
/* */
