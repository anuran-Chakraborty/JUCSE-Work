<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.addst = New System.Windows.Forms.Button()
        Me.delst = New System.Windows.Forms.Button()
        Me.editst = New System.Windows.Forms.Button()
        Me.srchst = New System.Windows.Forms.Button()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'addst
        '
        Me.addst.Location = New System.Drawing.Point(141, 58)
        Me.addst.Name = "addst"
        Me.addst.Size = New System.Drawing.Size(173, 23)
        Me.addst.TabIndex = 0
        Me.addst.Text = "Add Student"
        Me.addst.UseVisualStyleBackColor = True
        '
        'delst
        '
        Me.delst.Location = New System.Drawing.Point(141, 101)
        Me.delst.Name = "delst"
        Me.delst.Size = New System.Drawing.Size(173, 23)
        Me.delst.TabIndex = 1
        Me.delst.Text = "Delete Student"
        Me.delst.UseVisualStyleBackColor = True
        '
        'editst
        '
        Me.editst.Location = New System.Drawing.Point(141, 144)
        Me.editst.Name = "editst"
        Me.editst.Size = New System.Drawing.Size(173, 23)
        Me.editst.TabIndex = 2
        Me.editst.Text = "Edit Student"
        Me.editst.UseVisualStyleBackColor = True
        '
        'srchst
        '
        Me.srchst.Location = New System.Drawing.Point(141, 185)
        Me.srchst.Name = "srchst"
        Me.srchst.Size = New System.Drawing.Size(173, 23)
        Me.srchst.TabIndex = 3
        Me.srchst.Text = "Search Student"
        Me.srchst.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(141, 231)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(173, 23)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "Display All Records"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(470, 337)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.srchst)
        Me.Controls.Add(Me.editst)
        Me.Controls.Add(Me.delst)
        Me.Controls.Add(Me.addst)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents addst As Button
    Friend WithEvents delst As Button
    Friend WithEvents editst As Button
    Friend WithEvents srchst As Button
    Friend WithEvents Button1 As Button
End Class
