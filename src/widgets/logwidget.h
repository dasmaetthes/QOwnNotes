/*
 * Copyright (C) 2016 Patrizio Bekerle -- http://www.bekerle.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 */

#pragma once

#include <QFrame>

namespace Ui {
class LogWidget;
}

class LogWidget : public QFrame
{
    Q_OBJECT

public:
    enum LogType {
        DebugLogType,
        InfoLogType,
        WarningLogType,
        CriticalLogType,
        FatalLogType,
        StatusLogType,
        ScriptingLogType
    };

    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();
    static LogWidget *instance();
    static LogWidget *createInstance(QWidget *parent);
    void log(LogType logType, QString text);
    static void logMessageOutput(
            QtMsgType type,
            const QMessageLogContext &context,
            const QString &msg);

private slots:
    void storeSettings() const;

    void on_clearButton_clicked();

private:
    Ui::LogWidget *ui;
};
