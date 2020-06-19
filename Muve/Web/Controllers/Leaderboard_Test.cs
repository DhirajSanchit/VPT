using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web.Controllers
{
    public class Leaderboard_Test : Controller
    {
        // GET: Leaderboard_Test
        public ActionResult Index()
        {
            return View();
        }

        // GET: Leaderboard_Test/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: Leaderboard_Test/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Leaderboard_Test/Create
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

        // GET: Leaderboard_Test/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Leaderboard_Test/Edit/5
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

        // GET: Leaderboard_Test/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Leaderboard_Test/Delete/5
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
