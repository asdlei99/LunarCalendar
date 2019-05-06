#ifndef LUNARCALENDAR_H
#define LUNARCALENDAR_H

#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QDate>
#include <QTableView>
#include <QLabel>
#include <QComboBox>
#include <QToolButton>
#include <QPushButton>
#include "lunarcalendar_export.h"

class LUNARCALENDAR_EXPORT CLunarCalendar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QDate selectedDate WRITE SetSelectedDate READ SelectedDate)
    Q_PROPERTY(QString selectLunar READ SelectedLunar)
    Q_PROPERTY(int yearShow READ YearShown)
    Q_PROPERTY(int monthShow READ MonthShown)
    Q_PROPERTY(Qt::DayOfWeek firstDayOfWeek READ FirstDayOfWeek WRITE SetFirstDayOfWeek)
    Q_PROPERTY(QDate minimumDate READ MinimumDate WRITE SetMinimumDate)
    Q_PROPERTY(QDate maximumDate READ MaximumDate WRITE SetMaximumDate)
    Q_PROPERTY(bool showGrid READ ShowGrid WRITE SetShowGrid)
    Q_PROPERTY(bool showBackgroupImage READ ShowBackgroupImage WRITE SetShowBackgroupImage)
    
public:
    explicit CLunarCalendar(QWidget *parent = nullptr);
    virtual ~CLunarCalendar() override;
    
    static void InitResource();
    static void CLeanResource();
    
    QDate SelectedDate() const;
    void SetSelectedDate(const QDate &date);
    
    QString SelectedLunar();
    
    int YearShown() const;
    int MonthShown() const;
    
    Qt::DayOfWeek FirstDayOfWeek() const;
    void SetFirstDayOfWeek(Qt::DayOfWeek dayOfWeek);
    
    void SetShowGrid(bool show);
    bool ShowGrid();
    void SetShowBackgroupImage(bool show);
    bool ShowBackgroupImage();
    void SetShowToday(bool bShow);
    void SetShowWeekHead(bool bShow);
    void SetShowWeeks(bool bShow);
    void SetShowHead(bool bShow);
    void SetShowTime(bool bShow);
    void SetShowTools(bool bShow);
    
    QDate MinimumDate() const;
    void SetMinimumDate(const QDate &date);
    QDate MaximumDate() const;
    void SetMaximumDate(const QDate &date);
    void SetDateRange(const QDate &min, const QDate &max);

    int AddHoliday(int month, int day, const QString &szName);
    int AddAnniversary(int month, int day, const QString &szName);
    int AddLunarAnniversary(int month, int day, const QString &szName);
    
    enum _CalendarType{
        CalendarTypeSolar = 0x01,
        CalendarTypeLunar = 0x02
    };
    int SetCalendarType(_CalendarType type);
    _CalendarType GetCalendarType();
    enum _VIEW_TYPE{
        ViewTypeMonth,
        ViewTypeWeek
    };
    int SetViewType(_VIEW_TYPE type);
    _VIEW_TYPE GetViewType();
    
    int LoadCalendarTable(const QString& szFile);
    int GenerateCalendarTable(const QString& szFile, int nThreadNumber = 2, bool bSaveAllDate = true);
    
Q_SIGNALS:
    void sigSelectionChanged();

private slots:
    void on_tbNextYear_clicked();
    void on_tbPreviousYear_clicked();
    void on_tbNextMonth_clicked();
    void on_tbPreviousMonth_clicked();
    void on_pbToday_clicked();
    void on_cbMonth_currentIndexChanged(int index);
    void on_cbYear_currentIndex(int index);
    void on_tvMonth_pressed(const QModelIndex &index);
    
    void slotTimeout();
    
protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

private:
    int ShowSelectTitle();
    int UpdateViewModel();
    int UpdateMonthMenu();
    int EnableMonthMenu();
    int UpdateSelect();
    int SetBackgroup(const QString& szFile);
    int SetYearRange(int min, int max);
    
private:
    QComboBox m_cmbYear;
    QToolButton m_tbPreYear, m_tbNextYear;
    QComboBox m_cmbMonth;
    QToolButton m_tbPreMonth, m_tbNextMonth;
    QPushButton m_pbToday;
    QLabel m_lbDate, m_lbTime;
    QTableView m_View;

    int m_oldRow, m_oldCol;
    bool m_bShowToday;
    QTimer m_Timer;
    bool m_bShowBackgroupImage;
};

#endif // LUNARCALENDAR_H
