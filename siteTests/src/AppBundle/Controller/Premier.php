<?php
namespace AppBundle\Controller;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use AppBundle\Entity\Articles;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\CollectionType;
use Symfony\Component\Translation\Tests\StringClass;
use Doctrine\DBAL\Types\StringType;
use AppBundle\Entity\Search;

class Premier extends Controller
{
	/**
	 * @Route("/home", name="home")
	 */
	public function afficheHome()
	{
		$em = $this->getDoctrine()->getManager(); //On veut pouvoir afficher les actualités
		$articles = $em->getRepository('AppBundle:Articles')->getLatest(0,1);
		// replace this example code with whatever you need
		return $this->render('/default/premier.html.twig',array(
				'articles' => $articles,
		));
	}
	
	/**
	 * @Route("/articles", name="list_articles")
	 * @Route("/articles/")
	 */
	
	public function afficheArticles(Request $request)
	{
		$em = $this->getDoctrine()->getManager(); //On veut pouvoir afficher les actualités
		///// ATTENTION CE FORMULAIRE EST SENSIBLE AUX INJECTIONS SQL !!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		$search= new Search();
		$form= $this->createFormBuilder($search)
		->add('search',TextType::class,array('label' => false,'attr' => array(
          'class' => 'form-control', 'placeholder' => "Search" )))
		->add('send',SubmitType::class, array('attr' => array(
          'class' => 'class="btn btn-default')))
		->getForm()
		;
		
		$form->handleRequest($request);
		if ($form->isSubmitted() && $form->isValid()) {
			$task=$form->getData();
			$s=$task->getSearch();
			$articles = $em->getRepository('AppBundle:Articles')->getFromSearch($s);
		}
		else{
			$articles = $em->getRepository('AppBundle:Articles')->findAll();
		}
		
		return $this->render('/default/articles.html.twig',array(
				'articles' => $articles, 'form'=>$form->createView(),
		));
	}
	
	/**
	 * @Route("/articles/{id}", name="show_article", requirements={
	 * 				"id": "\d+"
	 * 	})
	 */
	public function afficheUnArticle($id)
	{
		$em = $this->getDoctrine()->getManager();
		$article = $em->getRepository('AppBundle:Articles')->find($id);
		if(!$article){ // ON vérifie que l'article a bien été trouvé.
			return $this->redirectToRoute("list_articles");
		}
		return $this->render('/default/show_article.html.twig',array(
				'article' => $article,
		));
		
	}
	
	/**
	 * @Route("/articles/{slug}")
	 */
	public function fauxIdArticle($slug)
	{
		return $this->redirectToRoute("list_articles");
	
	}
	
	/**
	 * @Route("/presentation")
	 */
	public function affichePresentation()
	{
		return $this->render('/default/presentation.html.twig');
	
	}
}

