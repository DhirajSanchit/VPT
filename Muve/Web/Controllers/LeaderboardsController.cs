using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web.Controllers
{
    public class LeaderboardsController : Controller
    {
        // GET: Leaderboards
        public ActionResult Index()
        {
            return View();
        }

        // GET: Leaderboards/Details/5
        public ActionResult Leaderboards()
        {
            return View();
        }

        public ActionResult Login()
        {
            return View();
        }


        // GET: Leaderboards/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Leaderboards/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Leaderboards/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Leaderboards/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Leaderboards/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Leaderboards/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
