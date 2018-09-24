/*!
 *  asd
 *
 *
 */

$.run({

    /**
     *
     */
    index: function () {
        console.log("INDEX")
        $.on('click', 'b0', function () {
            $.get('/api', {}, function (resp) {
                alert(resp)
            });
        })
    },

    /**
     *
     */
    settings: function () {
        console.log("SETTING")

    }
});
