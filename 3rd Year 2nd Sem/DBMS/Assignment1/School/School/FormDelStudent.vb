Imports School.StudentList
Public Class FormDelStudent
    Dim index As Integer
    Private Sub search_del_Click(sender As Object, e As EventArgs) Handles search_del.Click
        ' First check if roll number exists
        If (del_roll.Text = "") Then
            MessageBox.Show("Enter a roll to search")
            Return
        End If
        Dim flag As Integer
        flag = 0
        For i As Integer = 0 To stList.Count() - 1
            If (stList(i).getRoll() = del_roll.Text) Then
                flag = 1
                ' Set texts
                del_name.Text = stList(i).getName()
                del_dept.Text = stList(i).getDept()
                del_dcode.Text = stList(i).getDcode()
                index = i
                del_save.Enabled = True
            End If
        Next

        If (flag = 0) Then
            MessageBox.Show("Invalid roll number")
        End If
    End Sub

    Private Sub del_cancel_Click(sender As Object, e As EventArgs) Handles del_cancel.Click
        Me.Close()
    End Sub

    Private Sub del_save_Click(sender As Object, e As EventArgs) Handles del_save.Click
        If (del_roll.Text = "" Or del_name.Text = "" Or del_dept.Text = "") Then
            MessageBox.Show("Missing details")
            Return
        End If
        stList.RemoveAt(index)
        MessageBox.Show("Successfully deleted !!")
        Me.Close()
    End Sub
End Class