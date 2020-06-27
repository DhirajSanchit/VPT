using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;


namespace Web.Controllers
{
    public class HomeController : Controller
    {
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


    }
}