using Microsoft.Ajax.Utilities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;


namespace Web.Controllers
{
    public class HomeController : Controller
    {

         public bool LoggedIn = false;

        // GET: Home
        public ActionResult Index()
        {
            /**
            if(!LoggedIn()){
            // Send to login page
            return Redirect("/"){
            }
            }
            **/


                return View();
        }

        public ActionResult Leaderboards()
        {
            return View();
        }

        public ActionResult Login()
        {
            return View();
        }


    }
}