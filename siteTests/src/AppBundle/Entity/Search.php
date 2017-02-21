<?php
namespace AppBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Search
 *
 * @ORM\Table(name="Search")
 * @ORM\Entity(repositoryClass="AppBundle\Repository\SearchRepository")
 */
class Search
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
	 * @ORM\Column(name="body", type="string")
	 */
	private $search;

	public function __construct()
	{
		$this->search = new \Doctrine\Common\Collections\ArrayCollection();
	}

	public function getId(){
		return $this->id;
	}	
	
	public function getSearch(){
		return $this->search;
	}

	public function setSearch($newbody){
		$this->search=$newbody;
		return $this;
	}


}