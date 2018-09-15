$( document ).ready(function() {
    $("#top").remove();
    $("#doc-content").addClass("main-panel");
    $("#doc-content").removeAttr("style");
    $("div.header").before("<nav class='navbar navbar-default'><div class='container-fluid'><div class='navbar-header'><a class='navbar-brand' href='#'>Dashboard</a></div></div></nav>")
});