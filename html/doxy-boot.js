$( document ).ready(function() {
    $("#doc-content").addClass("main-panel");
    $("#doc-content").removeAttr("style");
    $("#doc-content").prepend($("#top").clone());
    $("#top:first").remove();
});
