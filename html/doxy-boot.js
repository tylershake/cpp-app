$( document ).ready(function() {
    $("#doc-content").addClass("main-panel");
    $("#doc-content").removeAttr("style");
    $("#doc-content").prepend($("#top").clone());
    $("#top:first").remove();
    $("div.header").wrapAll("<div class='content'></div>").wrapAll("<div class='container-fluid'></div>").wrapAll("<div class='row'></div>").wrapAll("<div class='col-md-12'></div>").wrapAll("<div class='card'></div>");
    $("div.card").append($("div.contents").clone());
    $("div.contents").eq(1).remove();
    $("div.textblock").contents().unwrap();
    $("div.contents").addClass("content").removeClass("contents");
    $("div.headertitle").contents().unwrap();
    $("div.title").contents().unwrap().wrapAll("<h4 class='title'></h4>");
    $("#doc-content").append("<footer class='footer'><div class='container-fluid'><nav class='pull-left'><ul><li><a href='http://localhost'>Homepage</a></li><li><a href='http://localhost'>Blog</a></li><li><a href='http://localhost'>Licenses</a></li></ul></nav><div class='copyright pull-right'>&copy; 2018 <a href='https://www.raytheon.com/ourcompany/bbn'>Raytheon BBN Technologies</a></div></div></footer>");
    $("#side-nav").addClass("sidebar").removeClass("ui-resizable").removeClass("side-nav-resizable").removeAttr("style").attr("data-background-color", "white").attr("data-active-color","danger");
    $("#nav-tree").wrapAll("<div class='sidebar-wrapper'></div>");
    $("div.sidebar-wrapper").prepend("<div class='logo'><a class='simple-text' href='localhost'>HOMEPAGE</a></div>");
    $("#nav-sync").remove();
    $("table.directory").addClass("table").addClass("table-striped");
});
