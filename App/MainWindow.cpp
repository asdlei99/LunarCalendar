// 作者：康林 <kl222@126.com>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLoggingCategory>
#include <QDate>
#include <QIcon>
#include <QDir>
#include <QApplication>
#include <QActionGroup>
#ifdef RABBITCOMMON
#include "DlgAbout.h"
#include "FrmUpdater.h"
#include "RabbitCommonTools.h"
#endif

static Q_LOGGING_CATEGORY(Logger, "App")
    
//! [Implement the onHandle function]
uint CHandler::onHandle(/*in*/const QDate& d, /*out*/QStringList& tasks){
    // 以年为周期
    if(d.day() == 20 && d.month() == 10)
    {
        // 表示显示圆点，也显示内容
        tasks << "t1";
        return 0;
    }
    
    // 以月为周期
    if(d.day() == 21)
    {
        // 表示只显示圆点，不显示内容
        return 1;
    }
    
    // 以周为周期
    if(Qt::Wednesday == d.dayOfWeek())
    {
        // 表示只显示圆点，不显示内容。建议用上面的方式
        tasks << QString();
        return 0;
    }
    
    // 单个任务
    if(d.day() == 22 && d.month() == 10 && d.year() == 2015)
    {
        // 表示只显示圆点，不显示内容
        return 1;
    }
    
    // 没有任务
    return 0;
}
//! [Implement the onHandle function]

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    //! [Instance CLunarCalendar]
    m_pLunarCalendar = new CLunarCalendar(this);
    if(!m_pLunarCalendar)
        throw std::bad_alloc();
    //! [Instance CLunarCalendar]
    
    QMenu* pViewMenu = menuBar()->addMenu(tr("View"));
    QAction* pAction = pViewMenu->addAction(tr("Lunar"),
                                            this, SLOT(slotActionLunar(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    
    pAction = pViewMenu->addAction(tr("Solar"),
                                   this, SLOT(slotActionSolar(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pViewMenu->addSeparator();
    
    QActionGroup* pViewTypeGroup = new QActionGroup(this);
    QAction* pViewMonth = pViewMenu->addAction(tr("Month"),
                                               this, SLOT(slotViewMonth()));
    pViewMonth->setCheckable(true);
    pViewMonth->setChecked(true);
    pViewTypeGroup->addAction(pViewMonth);
    QAction* pViewWeek = pViewMenu->addAction(tr("Week"),
                                              this, SLOT(slotViewWeek()));
    pViewWeek->setCheckable(true);
    pViewTypeGroup->addAction(pViewWeek);
    pViewMenu->addSeparator();

    //! [Set UI]
    pAction = pViewMenu->addAction(tr("Show Head"),
                                   m_pLunarCalendar, SLOT(ShowHead(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show Tools"),
                                   m_pLunarCalendar, SLOT(ShowTools(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show today"),
                                   m_pLunarCalendar, SLOT(ShowToday(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show date"),
                                   m_pLunarCalendar, SLOT(ShowDate(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show time"),
                                   m_pLunarCalendar, SLOT(ShowTime(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show week head"),
                                   m_pLunarCalendar, SLOT(ShowWeekHead(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show weeks"),
                                   m_pLunarCalendar, SLOT(ShowWeeks(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Show grid"),
                                   m_pLunarCalendar, SLOT(ShowGrid(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(false);
    pAction = pViewMenu->addAction(tr("Show tooltip"),
                                   m_pLunarCalendar, SLOT(EnableToolTip(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(true);
    pAction = pViewMenu->addAction(tr("Use backgroup image"),
                                   m_pLunarCalendar, SLOT(ShowBackgroupImage(bool)));
    pAction->setCheckable(true);
    pAction->setChecked(false);
    m_pLunarCalendar->ShowBackgroupImage(false);

    QActionGroup* pViewHeadposition = new QActionGroup(this);
    QMenu* pViewHeadpositionMenu = pViewMenu->addMenu(tr("Head position"));
    QAction* pHeadNot = pViewHeadpositionMenu->addAction(tr("Not"),
                                                         this, SLOT(slotHeadpositionNot()));
    pHeadNot->setCheckable(true);
    QAction* pHeadTop = pViewHeadpositionMenu->addAction(tr("Top"),
                                                         this, SLOT(slotHeadpositionTop()));
    pHeadTop->setCheckable(true);
    pHeadTop->setChecked(true);
    QAction* pHeadDown = pViewHeadpositionMenu->addAction(tr("Down"),
                                                          this, SLOT(slotHeadpositionDown()));
    pHeadDown->setCheckable(true);
    QAction* pHeadLeft = pViewHeadpositionMenu->addAction(tr("Left"),
                                                          this, SLOT(slotHeadpositionLeft()));
    pHeadLeft->setCheckable(true);
    QAction* pHeadRight = pViewHeadpositionMenu->addAction(tr("Right"),
                                                           this, SLOT(slotHeadpositionRight()));
    pHeadRight->setCheckable(true);
    pViewHeadposition->addAction(pHeadNot);
    pViewHeadposition->addAction(pHeadTop);
    pViewHeadposition->addAction(pHeadDown);
    pViewHeadposition->addAction(pHeadLeft);
    pViewHeadposition->addAction(pHeadRight);
    //! [Set UI]
    
    pViewMenu->addAction(tr("Clear holidays"), m_pLunarCalendar, SLOT(ClearHoliday()));
    pViewMenu->addSeparator();
    pViewMenu->addAction(RabbitCommon::CTools::Instance()->AddStyleMenu(pViewMenu));
    pViewMenu->addAction(tr("Genetate cache table"), this, SLOT(slotGenerateCalendarTable()));

#ifdef RABBITCOMMON
    QMenu* pHelp = menuBar()->addMenu(tr("Help"));
    CFrmUpdater updater;
    pHelp->addAction(updater.windowIcon(), tr("Update"),
                     this, SLOT(slotUpdate()));
    pHelp->addAction(windowIcon(), tr("About"), this, SLOT(slotAbout()));
    pHelp->addMenu(RabbitCommon::CTools::Instance()->GetLogMenu(this));
#endif
    
    //m_pLunarCalendar->setLocale(QLocale("zh_CN"));
    m_pLunarCalendar->SetSelectedDate(QDate(2015, 10, 8));
    
    //*/! [Add Holiday]
    m_pLunarCalendar->AddHoliday(10, 1, "h1");
    m_pLunarCalendar->AddHoliday(10, 1, "lh1",
                              CLunarCalendar::_CalendarType::CalendarTypeLunar);
    m_pLunarCalendar->Update();
    //! [Add Holiday] */

    //*! [Add Anniversary]
    m_pLunarCalendar->AddAnniversary(10, 1, "a1");
    m_pLunarCalendar->AddAnniversary(10, 1, "a2");
    m_pLunarCalendar->AddAnniversary(9, 29, "a3");
    m_pLunarCalendar->AddAnniversary(10, 24, "a4");
    m_pLunarCalendar->AddAnniversary(10, 26, "a5");
    m_pLunarCalendar->AddAnniversary(8, 17, "l1",
            CLunarCalendar::_CalendarType::CalendarTypeLunar);
    m_pLunarCalendar->AddAnniversary(8, 17, "l2",
            CLunarCalendar::_CalendarType::CalendarTypeLunar);
    m_pLunarCalendar->AddAnniversary(9, 10, "l3",
            CLunarCalendar::_CalendarType::CalendarTypeLunar);
    m_pLunarCalendar->Update();
    //! [Add Anniversary] */
    
    //! [Instance CHandler]
    m_Hnadler = QSharedPointer<CHandler>(new CHandler());
    //! [Instance CHandler]
    //! [Set user defined tasks with CTaskHandler]
    m_pLunarCalendar->SetTaskHandle(m_Hnadler);
    //! [Set user defined tasks with CTaskHandler]
    
    //*! [User defined tasks]
    m_pLunarCalendar->SetTaskHandle([](const QDate& d, QStringList& tasks)->uint {

        // 以年为周期
        if(d.day() == 10 && d.month() == 10)
        {
            // 表示显示圆点，也显示内容
            tasks << "辛亥革命纪念日";
            return 0;
        }

        // 以月为周期
        if(d.day() == 11)
        {
            // 表示只显示圆点，不显示内容
            return 1;
        }

        // 以周为周期
        if(Qt::Monday == d.dayOfWeek())
        {
            // 表示只显示圆点，不显示内容。建议用上面的方式
            tasks << QString();
            return 0;
        }

        // 单个任务
        if(d.day() == 12 && d.month() == 10 && d.year() == 2015)
        {
            // 表示只显示圆点，不显示内容
            return 1;
        }

        // 没有任务
        return 0;});
    //! [User defined tasks] */

    //m_pLunarCalendar->SetCalendarType(CLunarCalendar::CalendarTypeLunar);
    //m_pLunarCalendar->SetViewType(CLunarCalendar::ViewTypeWeek);
    //m_pLunarCalendar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setCentralWidget(m_pLunarCalendar);
    
    //! [sigSelectionChanged]
    bool check = connect(m_pLunarCalendar, SIGNAL(sigSelectionChanged()),
                         this, SLOT(slotUpdateCalendar()));
    Q_ASSERT(check);
    //! [sigSelectionChanged]
}

MainWindow::~MainWindow()
{
    delete ui;
}

//! \name help
//! @{
void MainWindow::slotAbout()
{
#ifdef RABBITCOMMON
    CDlgAbout about(this);
    QIcon icon = QIcon::fromTheme("calendar");
    if(icon.isNull()) return;
    auto sizeList = icon.availableSizes();
    if(sizeList.isEmpty()) return;
    QPixmap p = icon.pixmap(*sizeList.begin());
    about.m_AppIcon = p.toImage();
    about.m_szHomePage = "https://github.com/KangLin/LunarCalendar";
    about.m_szBuildTime = QString("%1/%2").arg(__DATE__, __TIME__);
    about.m_szCopyrightStartTime = "2019";
    about.m_szVersionRevision = LunarCalendar_REVISION;
#if defined (Q_OS_ANDROID)
    about.showMaximized();
#endif
    about.exec();
#endif
}

void MainWindow::slotUpdate()
{
#ifdef RABBITCOMMON
    CFrmUpdater* pUpdate = new CFrmUpdater();
    QIcon icon = QIcon::fromTheme("calendar");
    if(icon.isNull()) return;
    auto sizeList = icon.availableSizes();
    if(sizeList.isEmpty()) return;
    QPixmap p = icon.pixmap(*sizeList.begin());
    pUpdate->SetTitle(p.toImage());
#if defined (Q_OS_ANDROID)
    pUpdate->showMaximized();
#else
    pUpdate->show();
#endif
#endif
}
//! @}

//! [slotUpdateCalendar]
void MainWindow::slotUpdateCalendar()
{
    int y, m, d;
    m_pLunarCalendar->SelectedLunar(y, m, d);
    qDebug(Logger) << "\n"
        << "SelectedDate:" << m_pLunarCalendar->SelectedDate() << "\n"
        << "SelectedLunar:" << m_pLunarCalendar->SelectedLunar()
        << "(" << y << "年" << m << "月" << d << "日" << ")\n"
        << "Year:" << m_pLunarCalendar->GetShowYear() << "\n"
        << "Month:" << m_pLunarCalendar->GetShowMonth() << "\n"
        << "MinimumDate:" << m_pLunarCalendar->MinimumDate() << "\n"
        << "MaximumDate:" << m_pLunarCalendar->MaximumDate()
        ;
}
//! [slotUpdateCalendar]

void MainWindow::slotActionLunar(bool checked)
{
    if(checked)
        m_pLunarCalendar->SetCalendarType(
            static_cast<CLunarCalendar::_CalendarType>(
                static_cast<int>(CLunarCalendar::_CalendarType::CalendarTypeLunar)
                | static_cast<int>(m_pLunarCalendar->GetCalendarType())));
    else
        m_pLunarCalendar->SetCalendarType(
            static_cast<CLunarCalendar::_CalendarType>(
                ~static_cast<int>(CLunarCalendar::_CalendarType::CalendarTypeLunar)
                & static_cast<int>(m_pLunarCalendar->GetCalendarType())));
}

void MainWindow::slotActionSolar(bool checked)
{
    if(checked)
        m_pLunarCalendar->SetCalendarType(
            static_cast<CLunarCalendar::_CalendarType>(
                static_cast<int>(CLunarCalendar::_CalendarType::CalendarTypeSolar)
                | static_cast<int>(m_pLunarCalendar->GetCalendarType())));
    else
        m_pLunarCalendar->SetCalendarType(
            static_cast<CLunarCalendar::_CalendarType>(
                ~static_cast<int>(CLunarCalendar::_CalendarType::CalendarTypeSolar)
                & static_cast<int>(m_pLunarCalendar->GetCalendarType())));
}

void MainWindow::slotViewMonth()
{
    m_pLunarCalendar->SetViewType(CLunarCalendar::_VIEW_TYPE::ViewTypeMonth);
}

void MainWindow::slotViewWeek()
{
    m_pLunarCalendar->SetViewType(CLunarCalendar::_VIEW_TYPE::ViewTypeWeek);
}

void MainWindow::slotHeadpositionNot()
{
    m_pLunarCalendar->SetHeadposition(CLunarCalendar::_HEAD_position::Not);
}

void MainWindow::slotHeadpositionTop()
{
    m_pLunarCalendar->SetHeadposition(CLunarCalendar::_HEAD_position::Top);
}

void MainWindow::slotHeadpositionDown()
{
    m_pLunarCalendar->SetHeadposition(CLunarCalendar::_HEAD_position::Down);
}

void MainWindow::slotHeadpositionLeft()
{
    m_pLunarCalendar->SetHeadposition(CLunarCalendar::_HEAD_position::Left);
}

void MainWindow::slotHeadpositionRight()
{
    m_pLunarCalendar->SetHeadposition(CLunarCalendar::_HEAD_position::Right);
}

void MainWindow::slotGenerateCalendarTable()
{
    //TODO：自动生成指定日期内的农历缓存表，生成完后，把cache.dat放到Src\Resource\Data目录下
    //*
    m_pLunarCalendar->SetDateRange(QDate(2000, 1, 1), QDate(2119, 1, 1));
    QString szFileCache = qApp->applicationDirPath() + QDir::separator() + "cache.dat";
    m_pLunarCalendar->GenerateCalendarTable(szFileCache, 1, true, false);
    qInfo(Logger) << "Generate calendar cache table:" << szFileCache;
    m_pLunarCalendar->LoadCalendarTable(szFileCache);
    //*/
}
