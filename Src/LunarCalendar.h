#ifndef LUNARCALENDAR_H
#define LUNARCALENDAR_H

#include <QWidget>
#include "lunarcalendar_export.h"
#include <QMap>

namespace Ui {
class CLunarCalendar;
}

class LUNARCALENDAR_EXPORT CLunarCalendar : public QWidget
{
    Q_OBJECT
    
public:
    explicit CLunarCalendar(QWidget *parent = nullptr);
    virtual ~CLunarCalendar() override;
    
    QDate selectedDate() const;
    void setSelectedDate(const QDate &date);

public:
    int yearShown() const;
    int monthShown() const;
    
    Qt::DayOfWeek firstDayOfWeek() const;
    void setFirstDayOfWeek(Qt::DayOfWeek dayOfWeek);
    
    void setShowGrid(bool show);
    void setShowToday(bool bShow);
    void setShowWeekHead(bool bShow);
    void setShowWeeks(bool bShow);
    void setShowHead(bool bShow);
    
    QDate minimumDate() const;
    void setMinimumDate(const QDate &date);

    QDate maximumDate() const;
    void setMaximumDate(const QDate &date);
public Q_SLOTS:
    void setDateRange(const QDate &min, const QDate &max);

public:
    int AddHoliday(int month, int day, const QString &szName);
    
Q_SIGNALS:
    void sigSelectionChanged();

private slots:
    void on_tbNext_clicked();
    void on_tbPrevious_clicked();
    void on_pbToday_clicked();
    void on_cbMonth_currentIndexChanged(int index);
    void on_spYear_valueChanged(int value);
    void on_tvMonth_pressed(const QModelIndex &index);
    
protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
    
private:
    int ShowSelectTitle();
    int ChangeMonth();
    int UpdateMonthMenu();
    int UpdateSelect();
    
private:
    Ui::CLunarCalendar *ui;
    int m_oldRow, m_oldCol;
    bool m_bShowToday;
    bool m_bShowHead;
    bool m_bUpdate;
};

#endif // LUNARCALENDAR_H
