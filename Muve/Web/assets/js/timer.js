/*=========================================================================================
    File Name: widgets.js
    Description: widgets page content with different types of cards
    ----------------------------------------------------------------------------------------
    Item Name: Frest HTML Admin Template
    Version: 1.0
    Author: PIXINVENT
    Author URL: http://www.themeforest.net/user/pixinvent
==========================================================================================*/

$(document).ready(function () {

    var $primary = '#5A8DEE';
    var $success = '#39DA8A';
    var $danger = '#FF5B5C';
    var $warning = '#FDAC41';
    var $info = '#00CFDD';
    var $label_color = '#304156';
    var $danger_light = '#FFDEDE';
    var $gray_light = '#828D99';
    var $bg_light = "#f2f4f4";


    // Weekly Challenge
    // ----------

    var lineChartoptions = {
        chart: {
            height: 300,
            type: 'line',
            zoom: {
                enabled: false
            },
            toolbar: {
                show: false
            },
        },
        dataLabels: {
            enabled: false
        },
        stroke: {
            curve: 'straight',
            width: 3,
        },
        legend: {
            horizontalAlign: 'right',
            position: 'top',
            markers: {
                radius: 50,
                height: 8,
                width: 8
            },
            itemMargin: {
                horizontal: 20,
            }
        },
        colors: [$info, $success],
        series: [{
            name: "Emiel",
            data: [40, 45, 39, 10, 40, 27, 30, 42]
        }, {
            name: "Amit",
            data: [25, 30, 31, 12, 28, 27, 22, 28]
        }],
        tooltip: {
            x: {
                show: false,
            }
        },
        xaxis: {
            categories: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug'],
            axisBorder: {
                show: false,
            },
            axisTicks: {
                show: false,
            },
            labels: {
                style: {
                    colors: $gray_light
                }
            }
        },
        yaxis: {
            labels: {
                style: {
                    color: $gray_light
                }
            }
        },
        legend: {
            show: false
        }
    }

    var lineChart = new ApexCharts(
        document.querySelector("#statistics-line-chart"),
        lineChartoptions
    );

    lineChart.render();

    

    // Timer Chart
    // -----------
    const DefaultTimer = 120; // Time in seconds
    let TimerCount = DefaultTimer;

    var TimerChartOptions = {
        chart: {
            height: 360,
            type: 'radialBar',
        },
        plotOptions: {
            radialBar: {
                hollow: {
                    margin: 15,
                    size: "60%"
                },
                startAngle: -135,
                endAngle: 135,
                dataLabels: {
                    name: {
                        fontSize: '22px',
                        color: '#304156'
                    },
                    value: {
                        fontSize: '20px',
                        color: '#828d99',
                        formatter: function (val) {
                            console.log((Math.floor(val / 60)) + ":" + (val - Math.floor(val / 60) * 60));
                            return (Math.floor(val / 60)) + ":" + (Math.floor(val % 60).toString().padStart(2, '0'));
                        }
                    }
                }
            }
        },
        stroke: {
            lineCap: 'round'
        },
        fill: {
            colors: [$warning]
        },
        series: [DefaultTimer],
        labels: ['time remaining'],
    }

    var TimerChart = new ApexCharts(
        document.querySelector("#gauge-chart"),
        TimerChartOptions
    );
    TimerChart.render();

    timer = setInterval(function ()
    {
        TimerCount--;
        if (TimerCount == 0) {
            clearInterval(timer);
        }

        TimerChart.updateSeries([TimerCount], false);

    }, 1000);
    // Perfect Scrollbar
    //------------------
    // Widget - User Details -Perfect Scrollbar X
    if ($('.widget-user-details .table-responsive').length > 0) {
        var user_details = new PerfectScrollbar('.widget-user-details .table-responsive');
    }

    // Widget - Card Overlay - Perfect Scrollbar X - on initial level
    if ($('.widget-overlay-content .table-responsive').length > 0) {
        var card_overlay = new PerfectScrollbar('.widget-overlay-content .tab-pane.active .table-responsive');
    }

    // Widget - Card Overlay - Perfect Scrollbar X - on active tab-pane
    $('.widget-overlay-content a[data-toggle="tab"]').on('shown.bs.tab', function (e) {
        var card_overlay = new PerfectScrollbar('.widget-overlay-content .tab-pane.active .table-responsive');
    })

    // Widget - earnings perfect scrollbar initialization
    if ($(".widget-earnings-scroll").length > 0) {
        var widget_earnings = new PerfectScrollbar(".widget-earnings-scroll",
            // horizontal scroll with mouse wheel
            {
                suppressScrollY: true,
                useBothWheelAxes: true
            });
    }

});
