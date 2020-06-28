<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="Dashboard.aspx.cs" Inherits="Web.Dashboard" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
                <section id="widgets-Statistics">
                    <div class="row">
                        <div class="col-12 mt-1 mb-2">
                            <h4>Account Dashboard</h4>
                            <hr>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xl-3 col-md-3 col-sm-6">
                            <div class="card text-center">
                                <div class="card-content">
                                    <div class="card-body">
                                        <div class="badge-circle badge-circle-lg badge-circle-light-info mx-auto my-1">
                                            <i class="bx bx-edit-alt font-medium-5"></i>
                                        </div>
                                        <p class="text-muted mb-0 line-ellipsis">Total game played</p>
                                        <h2 class="mb-0">480</h2>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-xl-3 col-md-3 col-sm-6">
                            <div class="card text-center">
                                <div class="card-content">
                                    <div class="card-body">
                                        <div class="badge-circle badge-circle-lg badge-circle-light-warning mx-auto my-1">
                                            <i class="bx bx-file font-medium-5"></i>
                                        </div>
                                        <p class="text-muted mb-0 line-ellipsis">Games played today</p>
                                        <h2 class="mb-0">17</h2>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-xl-3 col-md-3 col-sm-6">
                            <div class="card text-center">
                                <div class="card-content">
                                    <div class="card-body">
                                        <div class="badge-circle badge-circle-lg badge-circle-light-danger mx-auto my-1">
                                            <i class="bx bx-message font-medium-5"></i>
                                        </div>
                                        <p class="text-muted mb-0 line-ellipsis">Challenges won</p>
                                        <h2 class="mb-0">6</h2>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-xl-3 col-md-3 col-sm-6">
                            <div class="card text-center">
                                <div class="card-content">
                                    <div class="card-body">
                                        <div class="badge-circle badge-circle-lg badge-circle-light-primary mx-auto my-1">
                                            <i class="bx bx-money font-medium-5"></i>
                                        </div>
                                        <p class="text-muted mb-0 line-ellipsis">Challenges lost</p>
                                        <h2 class="mb-0">2</h2>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </section>
                <!-- Widgets Statistics End -->

                <!-- Widgets Charts start -->
                <section id="widgets-chart">
                    <div class="row">
                        <!-- Gauge Chart Starts -->
                        <div class="col-lg-4 col-md-6">
                            <div class="card">
                                <div class="card-header border-bottom d-flex justify-content-between align-items-center">
                                    <h4 class="card-title">Timer</h4>
                                    <ul class="list-inline mb-0">
                                        <li class="mr-50"> <i class="bullet bullet-xs bullet-warning mr-50"></i>Time remaining</li>
                                        <li><i class="bx bx-dots-vertical-rounded font-medium-3 align-middle cursor-pointer"></i></li>
                                    </ul>
                                </div>
                                <div class="card-content">
                                    <div class="card-body">
                                        <div id="gauge-chart" class="mb-2"></div>
                                        <p class="text-center">Time remaining till next excercise.</p>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <!-- Gauge Chart Ends -->
                        <!-- Challenge progress Chart Starts -->
                        <div class="col-lg-5">
                            <div class="card">
                                <div class="card-header border-bottom d-flex justify-content-between align-items-center">
                                    <h4 class="card-title">Weekly Challenge</h4>
                                    <ul class="list-inline mb-0">
                                        <li class="mr-50"> <i class="bullet bullet-xs bullet-info mr-50"></i>Emiel </li>
                                        <li class="mr-1"> <i class="bullet bullet-xs bullet-success mr-50"></i>Amit </li>
                                        <li><i class="bx bx-dots-vertical-rounded font-medium-3 align-middle cursor-pointer"></i></li>
                                    </ul>
                                </div>
                                <div class="card-content">
                                    <div class="card-body">
                                        <div id="statistics-line-chart"></div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <!-- Challenge progress Chart Ends -->
                        <!-- Leaderboard progress Chart Starts -->
                        <div class="col-xl-3 col-md-6 col-12 profit-report-card">
                          <div class="row">
                            <div class="col-md-12 col-sm-6">
                              <div class="card">
                                <div class="card-header d-flex justify-content-between align-items-center">
                                  <h4 class="card-title">Today vs Yesterday</h4>
                                  <i class="bx bx-dots-vertical-rounded font-medium-3 cursor-pointer"></i>
                                </div>
                                <div class="card-content">
                                  <div class="card-body pb-0 d-flex justify-content-around">
                                    <div class="d-inline-flex mr-xl-2" style="position: relative;">
                                      <div id="profit-primary-chart" style="min-height: 91.4146px;"><div id="apexchartse21vx349" class="apexcharts-canvas apexchartse21vx349 light" style="width: 40px; height: 91.4146px;"><svg id="SvgjsSvg1402" width="40" height="91.41463414634147" xmlns="http://www.w3.org/2000/svg" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:svgjs="http://svgjs.com/svgjs" class="apexcharts-svg" xmlns:data="ApexChartsNS" transform="translate(0, 0)" style="background: transparent;"><g id="SvgjsG1404" class="apexcharts-inner apexcharts-graphical" transform="translate(-12.5, 0)"><defs id="SvgjsDefs1403"><clipPath id="gridRectMaske21vx349"><rect id="SvgjsRect1405" width="67" height="77" x="-1" y="-1" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath><clipPath id="gridRectMarkerMaske21vx349"><rect id="SvgjsRect1406" width="67" height="77" x="-1" y="-1" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath></defs><g id="SvgjsG1408" class="apexcharts-radialbar"><g id="SvgjsG1409"><g id="SvgjsG1410" class="apexcharts-tracks"><g id="SvgjsG1411" class="apexcharts-radialbar-track apexcharts-track" rel="1"><path id="apexcharts-radialbarTrack-0" d="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 32.497432450407324 17.78902461430487" fill="none" fill-opacity="1" stroke="rgba(242,242,242,0.85)" stroke-opacity="1" stroke-linecap="round" stroke-width="3.877634146341464" stroke-dasharray="0" class="apexcharts-radialbar-area" data:pathOrig="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 32.497432450407324 17.78902461430487"></path></g></g><g id="SvgjsG1413"><g id="SvgjsG1416" class="apexcharts-series apexcharts-radial-series" seriesName="seriesx1" rel="1" data:realIndex="0"><path id="SvgjsPath1417" d="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 0 1 32.5 47.2109756097561" fill="none" fill-opacity="0.85" stroke="rgba(90,141,238,0.85)" stroke-opacity="1" stroke-linecap="round" stroke-width="3.9975609756097565" stroke-dasharray="0" class="apexcharts-radialbar-area apexcharts-radialbar-slice-0" data:angle="180" data:value="50" index="0" j="0" data:pathOrig="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 0 1 32.5 47.2109756097561"></path></g><circle id="SvgjsCircle1414" r="7.772158536585366" cx="32.5" cy="32.5" class="apexcharts-radialbar-hollow" fill="transparent"></circle><g id="SvgjsG1415" class="apexcharts-datalabels-group" transform="translate(0, 0)" style="opacity: 1;"></g></g></g></g><line id="SvgjsLine1418" x1="0" y1="0" x2="65" y2="0" stroke="#b6b6b6" stroke-dasharray="0" stroke-width="1" class="apexcharts-ycrosshairs"></line><line id="SvgjsLine1419" x1="0" y1="0" x2="65" y2="0" stroke-dasharray="0" stroke-width="0" class="apexcharts-ycrosshairs-hidden"></line></g></svg><div class="apexcharts-legend"></div></div></div>
                                      <div class="profit-content ml-50 mt-50">
                                        <h5 class="mb-0">15</h5>
                                        <small class="text-muted">Today</small>
                                      </div>
                                    <div class="resize-triggers"><div class="expand-trigger"><div style="width: 91px; height: 93px;"></div></div><div class="contract-trigger"></div></div></div>
                                    <div class="d-inline-flex" style="position: relative;">
                                      <div id="profit-info-chart" style="min-height: 91.4146px;"><div id="apexchartsbew9ejo3" class="apexcharts-canvas apexchartsbew9ejo3 light" style="width: 40px; height: 91.4146px;"><svg id="SvgjsSvg1420" width="40" height="91.41463414634147" xmlns="http://www.w3.org/2000/svg" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:svgjs="http://svgjs.com/svgjs" class="apexcharts-svg" xmlns:data="ApexChartsNS" transform="translate(0, 0)" style="background: transparent;"><g id="SvgjsG1422" class="apexcharts-inner apexcharts-graphical" transform="translate(-12.5, 0)"><defs id="SvgjsDefs1421"><clipPath id="gridRectMaskbew9ejo3"><rect id="SvgjsRect1423" width="67" height="77" x="-1" y="-1" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath><clipPath id="gridRectMarkerMaskbew9ejo3"><rect id="SvgjsRect1424" width="67" height="77" x="-1" y="-1" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath></defs><g id="SvgjsG1426" class="apexcharts-radialbar"><g id="SvgjsG1427"><g id="SvgjsG1428" class="apexcharts-tracks"><g id="SvgjsG1429" class="apexcharts-radialbar-track apexcharts-track" rel="1"><path id="apexcharts-radialbarTrack-0" d="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 32.497432450407324 17.78902461430487" fill="none" fill-opacity="1" stroke="rgba(242,242,242,0.85)" stroke-opacity="1" stroke-linecap="round" stroke-width="3.877634146341464" stroke-dasharray="0" class="apexcharts-radialbar-area" data:pathOrig="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 32.497432450407324 17.78902461430487"></path></g></g><g id="SvgjsG1431"><g id="SvgjsG1434" class="apexcharts-series apexcharts-radial-series" seriesName="seriesx1" rel="1" data:realIndex="0"><path id="SvgjsPath1435" d="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 18.509030785282395 37.04594146724999" fill="none" fill-opacity="0.85" stroke="rgba(0,207,221,0.85)" stroke-opacity="1" stroke-linecap="round" stroke-width="3.9975609756097565" stroke-dasharray="0" class="apexcharts-radialbar-area apexcharts-radialbar-slice-0" data:angle="252" data:value="70" index="0" j="0" data:pathOrig="M 32.5 17.789024390243902 A 14.710975609756098 14.710975609756098 0 1 1 18.509030785282395 37.04594146724999"></path></g><circle id="SvgjsCircle1432" r="7.772158536585366" cx="32.5" cy="32.5" class="apexcharts-radialbar-hollow" fill="transparent"></circle><g id="SvgjsG1433" class="apexcharts-datalabels-group" transform="translate(0, 0)" style="opacity: 1;"></g></g></g></g><line id="SvgjsLine1436" x1="0" y1="0" x2="65" y2="0" stroke="#b6b6b6" stroke-dasharray="0" stroke-width="1" class="apexcharts-ycrosshairs"></line><line id="SvgjsLine1437" x1="0" y1="0" x2="65" y2="0" stroke-dasharray="0" stroke-width="0" class="apexcharts-ycrosshairs-hidden"></line></g></svg><div class="apexcharts-legend"></div></div></div>
                                      <div class="profit-content ml-50 mt-50">
                                        <h5 class="mb-0">10</h5>
                                        <small class="text-muted">Yesterday</small>
                                      </div>
                                    <div class="resize-triggers"><div class="expand-trigger"><div style="width: 95px; height: 93px;"></div></div><div class="contract-trigger"></div></div></div>
                                  </div>
                                </div>
                              </div>
                            </div>
                            <div class="col-md-12 col-sm-6">
                              <div class="card">
                                <div class="card-header">
                                  <h4 class="card-title">Leaderboard</h4>
                                </div>
                                <div class="card-content">
                                  <div class="card-body">
                                    <div class="d-flex align-items-end justify-content-around" style="position: relative;">
                                      <div class="registration-content mr-xl-2">
                                        <h4 class="mb-0">#149</h4>
                                        <i class="bx bx-trending-up success align-middle"></i>
                                        <span class="text-success">12.8%</span>
                                      </div>
                                      <div id="registration-chart" style="min-height: 60px;"><div id="apexchartsrltuvoqt" class="apexcharts-canvas apexchartsrltuvoqt light" style="width: 120px; height: 60px;"><svg id="SvgjsSvg1438" width="120" height="60" xmlns="http://www.w3.org/2000/svg" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:svgjs="http://svgjs.com/svgjs" class="apexcharts-svg" xmlns:data="ApexChartsNS" transform="translate(0, 0)" style="background: transparent;"><g id="SvgjsG1440" class="apexcharts-inner apexcharts-graphical" transform="translate(0, 0)"><defs id="SvgjsDefs1439"><linearGradient id="SvgjsLinearGradient1443" x1="0" y1="0" x2="0" y2="1"><stop id="SvgjsStop1444" stop-opacity="0.4" stop-color="rgba(216,227,240,0.4)" offset="0"></stop><stop id="SvgjsStop1445" stop-opacity="0.5" stop-color="rgba(190,209,230,0.5)" offset="1"></stop><stop id="SvgjsStop1446" stop-opacity="0.5" stop-color="rgba(190,209,230,0.5)" offset="1"></stop></linearGradient><clipPath id="gridRectMaskrltuvoqt"><rect id="SvgjsRect1448" width="120" height="60" x="0" y="0" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath><clipPath id="gridRectMarkerMaskrltuvoqt"><rect id="SvgjsRect1449" width="122" height="62" x="-1" y="-1" rx="0" ry="0" fill="#ffffff" opacity="1" stroke-width="0" stroke="none" stroke-dasharray="0"></rect></clipPath></defs><rect id="SvgjsRect1447" width="14" height="60" x="105" y="0" rx="0" ry="0" fill="url(#SvgjsLinearGradient1443)" opacity="1" stroke-width="0" stroke-dasharray="3" class="apexcharts-xcrosshairs" y2="60" filter="none" fill-opacity="0.9" x1="105" x2="105"></rect><g id="SvgjsG1461" class="apexcharts-xaxis" transform="translate(0, 0)"><g id="SvgjsG1462" class="apexcharts-xaxis-texts-g" transform="translate(0, 1.875)"></g></g><g id="SvgjsG1465" class="apexcharts-grid"><line id="SvgjsLine1467" x1="0" y1="60" x2="120" y2="60" stroke="transparent" stroke-dasharray="0"></line><line id="SvgjsLine1466" x1="0" y1="1" x2="0" y2="60" stroke="transparent" stroke-dasharray="0"></line></g><g id="SvgjsG1451" class="apexcharts-bar-series apexcharts-plot-series"><g id="SvgjsG1452" class="apexcharts-series" rel="1" seriesName="Sessions" data:realIndex="0"><path id="undefined-0" d="M0.5 60L0.5 48L14.5 48L14.5 60L0.5 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 0.5 60L 0.5 48L 14.5 48L 14.5 60L 0.5 60" pathFrom="M 0.5 60L 0.5 60L 14.5 60L 14.5 60L 0.5 60" cy="48" cx="14.5" j="0" val="3" barHeight="12" barWidth="14"></path><path id="undefined-0" d="M18 60L18 32L32 32L32 60L18 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 18 60L 18 32L 32 32L 32 60L 18 60" pathFrom="M 18 60L 18 60L 32 60L 32 60L 18 60" cy="32" cx="32" j="1" val="7" barHeight="28" barWidth="14"></path><path id="undefined-0" d="M35.5 60L35.5 40L49.5 40L49.5 60L35.5 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 35.5 60L 35.5 40L 49.5 40L 49.5 60L 35.5 60" pathFrom="M 35.5 60L 35.5 60L 49.5 60L 49.5 60L 35.5 60" cy="40" cx="49.5" j="2" val="5" barHeight="20" barWidth="14"></path><path id="undefined-0" d="M53 60L53 0L67 0L67 60L53 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 53 60L 53 0L 67 0L 67 60L 53 60" pathFrom="M 53 60L 53 60L 67 60L 67 60L 53 60" cy="0" cx="67" j="3" val="15" barHeight="60" barWidth="14"></path><path id="undefined-0" d="M70.5 60L70.5 24L84.5 24L84.5 60L70.5 60 " fill="rgba(253,172,65,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 70.5 60L 70.5 24L 84.5 24L 84.5 60L 70.5 60" pathFrom="M 70.5 60L 70.5 60L 84.5 60L 84.5 60L 70.5 60" cy="24" cx="84.5" j="4" val="9" barHeight="36" barWidth="14"></path><path id="undefined-0" d="M88 60L88 28L102 28L102 60L88 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 88 60L 88 28L 102 28L 102 60L 88 60" pathFrom="M 88 60L 88 60L 102 60L 102 60L 88 60" cy="28" cx="102" j="5" val="8" barHeight="32" barWidth="14"></path><path id="undefined-0" d="M105.5 60L105.5 12L119.5 12L119.5 60L105.5 60 " fill="rgba(255,238,217,0.85)" fill-opacity="1" stroke-opacity="1" stroke-linecap="butt" stroke-width="0" stroke-dasharray="0" class="apexcharts-bar-area" index="0" clip-path="url(#gridRectMaskrltuvoqt)" pathTo="M 105.5 60L 105.5 12L 119.5 12L 119.5 60L 105.5 60" pathFrom="M 105.5 60L 105.5 60L 119.5 60L 119.5 60L 105.5 60" cy="12" cx="119.5" j="6" val="12" barHeight="48" barWidth="14"></path><g id="SvgjsG1453" class="apexcharts-datalabels"></g></g></g><line id="SvgjsLine1468" x1="0" y1="0" x2="120" y2="0" stroke="#b6b6b6" stroke-dasharray="0" stroke-width="1" class="apexcharts-ycrosshairs"></line><line id="SvgjsLine1469" x1="0" y1="0" x2="120" y2="0" stroke-dasharray="0" stroke-width="0" class="apexcharts-ycrosshairs-hidden"></line><g id="SvgjsG1470" class="apexcharts-yaxis-annotations"></g><g id="SvgjsG1471" class="apexcharts-xaxis-annotations"></g><g id="SvgjsG1472" class="apexcharts-point-annotations"></g></g><g id="SvgjsG1463" class="apexcharts-yaxis" rel="0" transform="translate(-21, 0)"><g id="SvgjsG1464" class="apexcharts-yaxis-texts-g"></g></g></svg><div class="apexcharts-legend"></div><div class="apexcharts-tooltip light" style="left: -7.65278px; top: -4.5px;"><div class="apexcharts-tooltip-series-group active" style="display: flex;"><span class="apexcharts-tooltip-marker" style="background-color: rgb(255, 238, 217);"></span><div class="apexcharts-tooltip-text" style="font-family: Helvetica, Arial, sans-serif; font-size: 12px;"><div class="apexcharts-tooltip-y-group"><span class="apexcharts-tooltip-text-label">Sessions: </span><span class="apexcharts-tooltip-text-value">12</span></div><div class="apexcharts-tooltip-z-group"><span class="apexcharts-tooltip-text-z-label"></span><span class="apexcharts-tooltip-text-z-value"></span></div></div></div></div></div></div>
                                    <div class="resize-triggers"><div class="expand-trigger"><div style="width: 268px; height: 61px;"></div></div><div class="contract-trigger"></div></div></div>
                                  </div>
                                </div>
                              </div>
                            </div>
                          </div>
                        </div>
                        <!-- Leaderboard progress Chart Ends -->
                    </div>
                </section>
</asp:Content>
