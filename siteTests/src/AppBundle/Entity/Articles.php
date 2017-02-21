<?php
namespace AppBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Articles
 *
 * @ORM\Table(name="Articles")
 * @ORM\Entity(repositoryClass="AppBundle\Repository\ArticlesRepository")
 */
class Articles
{
	/**
	 * @var int
	 *
	 * @ORM\Column(name="id", type="integer")
	 * @ORM\Id
	 * @ORM\GeneratedValue(strategy="AUTO")
	 */
	private $id;
	
	/**
	 * @var string
	 *
	 * @ORM\Column(name="date", type="string", length=100)
	 */
	private $date;
	
	/**
	 * @var string
	 *
	 * @ORM\Column(name="title", type="string", length=100)
	 */
	private $title;
	
	
	/**
	 * @var string
	 *
	 * @ORM\Column(name="body", type="string")
	 */
	private $body;
	
	public function __construct()
	{
		$this->date = new \Doctrine\Common\Collections\ArrayCollection();
		$this->title = new \Doctrine\Common\Collections\ArrayCollection();
		$this->body = new \Doctrine\Common\Collections\ArrayCollection();
	}
	
	public function getId(){
		return $this->id;	
	}
	
	public function getDate(){
		return $this->date;
	}
	
	public function setDate($newdate){
		$this->date=$newdate;
		return $this;
	}
	
	public function getTitle(){
		return $this->title;
	}
	
	public function setTitle($newtitle){
		$this->title=$newtitle;
		return $this;
	}
	
	public function getBody(){
		return $this->body;
	}
	
	public function setBody($newbody){
		$this->body=$newbody;
		return $this;
	}
	
	
}