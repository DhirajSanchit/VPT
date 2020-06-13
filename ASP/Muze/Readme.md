# Project installation

## Database 
_There is no database connection possible at this moment_

## The Application

- Open the project in Visual Studio
- Run with IIS Express in your preferred browser

You will probably see some error message (HTTP Error 403.14 - Forbidden).
To fix this add the following string to the end of the URL:
`/Dashboard.aspx`
Your URL will now look like this `localhost:60265/Dashboard.aspx`. Hit enter and the page should load correctly.

# Adding a new page
_Adding a new page to the project using Visual Studio_

- Right click the Muze.Master file in the Solution Explorer
- Click on Add Content Page
A new WebForm.aspx has been created. Rename the file to your preferred page name.